#include "ThunderbirdApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<ThunderbirdApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

ThunderbirdApp::ThunderbirdApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  ThunderbirdApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  ThunderbirdApp::associateSyntax(_syntax, _action_factory);
}

ThunderbirdApp::~ThunderbirdApp()
{
}

// External entry point for dynamic application loading
extern "C" void ThunderbirdApp__registerApps() { ThunderbirdApp::registerApps(); }
void
ThunderbirdApp::registerApps()
{
  registerApp(ThunderbirdApp);
}

// External entry point for dynamic object registration
extern "C" void ThunderbirdApp__registerObjects(Factory & factory) { ThunderbirdApp::registerObjects(factory); }
void
ThunderbirdApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void ThunderbirdApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { ThunderbirdApp::associateSyntax(syntax, action_factory); }
void
ThunderbirdApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
