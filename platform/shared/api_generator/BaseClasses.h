#pragma once

#include "common/RhoStd.h"
#include "common/StringConverter.h"
#include "GeneratorQueue.h"

namespace rho
{
namespace apiGenerator
{
/*
template<typename ModuleClass>
class CModuleBase: public ModuleClass
{
protected:

    rho::StringW m_strID;
    rho::Hashtable<rho::StringW, rho::StringW> m_hashProps;

public:
    CModuleBase(const rho::StringW& strID)
    {
        m_strID = strID;
    }

    virtual void getProperty( const rho::StringW& propertyName, CMethodResult& oResult)
    {
        oResult.set(m_hashProps[propertyName]);
    }

    virtual void getProperties( const rho::Vector<rho::StringW>& arrayofNames, CMethodResult& oResult)
    {
        rho::Hashtable<rho::StringW, rho::StringW> res;
        oResult.setCollectionMode(true);
        for ( int i = 0; i < (int)arrayofNames.size(); i++ )
        {
            getProperty(arrayofNames[i], oResult);

            if ( oResult.isError() )
                break;

            res[arrayofNames[i]] = oResult.toString();
        }

        oResult.setCollectionMode(false);
        if ( oResult.isError() )
            oResult.callCallback();
        else
            oResult.set(res);
    }

    virtual void getAllProperties(CMethodResult& oResult)
    {
        oResult.set(m_hashProps);
    }

    virtual void setProperty( const rho::StringW& propertyName,  const rho::StringW& propertyValue, CMethodResult& oResult)
    {
        m_hashProps.put(propertyName, propertyValue);
    }

    virtual void setProperties( const rho::Hashtable<rho::StringW, rho::StringW>& propertyMap, CMethodResult& oResult)
    {
        for ( rho::Hashtable<rho::StringW, rho::StringW>::const_iterator it = propertyMap.begin();  it != propertyMap.end(); ++it )
        {
            setProperty( it->first, it->second, oResult );
            if ( oResult.isError() )
                break;
        }
    }

    virtual void clearAllProperties(CMethodResult& oResult)
    {
        m_hashProps.clear();
    }

};*/

template<typename ModuleClass>
class CModuleSingletonBase : public ModuleClass
{
protected:
    rho::common::CAutoPtr<rho::common::CThreadQueue> m_pCommandQueue;

    class CCallInThread : public rho::common::CRhoThread
    {
        rho::common::CAutoPtr<rho::common::IRhoRunnable> m_pFunctor;
    public:
        CCallInThread(rho::common::IRhoRunnable* pFunctor): CRhoThread(), m_pFunctor(pFunctor)
        {
            start(epNormal);
        }
        
    private:
        virtual void run(){ m_pFunctor->runObject();  }
        virtual void runObject() {
            rho::common::CRhoThread::runObject();
            delete this;
        }
    };

public:

    void setCommandQueue( rho::common::CThreadQueue* pQueue){ m_pCommandQueue = pQueue; }
    virtual void addCommandToQueue(rho::common::IRhoRunnable* pFunctor)
    {
        if ( !m_pCommandQueue )
        {
            m_pCommandQueue = new CGeneratorQueue();
            m_pCommandQueue->start(rho::common::CThreadQueue::epLow);
        }

        m_pCommandQueue->addQueueCommand( new CGeneratorQueue::CGeneratorQueueCommand(pFunctor) );
    }

    virtual void callCommandInThread(rho::common::IRhoRunnable* pFunctor)
    {
        new CCallInThread(pFunctor);
    }
};

template<typename ModuleClass, typename SingletonClass, typename BaseClass>
class CModuleFactoryBase : public BaseClass
{
protected:
    common::CAutoPtr<SingletonClass> m_pModuleSingleton;

public:

    virtual SingletonClass* getModuleSingleton()
    {
        if ( !m_pModuleSingleton )
            m_pModuleSingleton = createModuleSingleton();

        return m_pModuleSingleton;
    }

    virtual SingletonClass* createModuleSingleton() = 0;

};

template<typename ModuleClass>
class CMethodAccessor
{
public:
    typedef void (ModuleClass::*TGetter)(CMethodResult& oResult);

    struct CSetterBase
    {
        virtual void call(ModuleClass* pModule, const rho::String& strArg, CMethodResult& oResult ) = 0;
    };
    template<typename TArg, typename TValue>        
    class CSetter: public CSetterBase
    {
        typedef void (ModuleClass::*TSetter)(TArg arg, CMethodResult& oResult);
        TSetter m_pSetterFunc;
    public:
        CSetter( TSetter pSetter ) : m_pSetterFunc(pSetter){}
        virtual void call(ModuleClass* pModule, const rho::String& strArg, CMethodResult& oResult )
        {
            TValue arg;
            rho::common::convertFromStringA( strArg.c_str(), arg );
            (pModule->*m_pSetterFunc)( arg, oResult );
        }
    };
private:
    TGetter m_pGetter;
    CSetterBase* m_pSetter;
public:
    CMethodAccessor( TGetter pGetter) : m_pGetter(pGetter), m_pSetter(0){}

    void addSetter(CSetterBase* pSetter){ m_pSetter = pSetter; }
    void callGetter( ModuleClass* pModule, CMethodResult& oResult ){ (pModule->*m_pGetter)(oResult); }
    void callSetter( ModuleClass* pModule, const rho::String& strArg, CMethodResult& oResult){ m_pSetter->call( pModule, strArg, oResult); }
    bool hasSetter()const{ return m_pSetter != 0; }
};

}
}