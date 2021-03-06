#pragma once

#include "common/RhoStd.h"
#include "api_generator/MethodResult.h"
#include "api_generator/BaseClasses.h"


namespace rho {
///////////////////////////////////////////////////////////
struct IJavascriptVM
{
//constants


//methods
    virtual ~IJavascriptVM(){}


};

struct IJavascriptVMSingleton
{
    virtual ~IJavascriptVMSingleton(){}

    virtual void executeScript( const rho::StringW& script, rho::apiGenerator::CMethodResult& oResult) = 0;


    virtual void addCommandToQueue(rho::common::IRhoRunnable* pFunctor) = 0;
    virtual void callCommandInThread(rho::common::IRhoRunnable* pFunctor) = 0;
};

struct IJavascriptVMFactory
{
    virtual ~IJavascriptVMFactory(){}

    virtual IJavascriptVMSingleton* getModuleSingleton() = 0;


};


}
