#ifndef THUNDERBIRDAPP_H
#define THUNDERBIRDAPP_H

#include "MooseApp.h"

class ThunderbirdApp;

template<>
InputParameters validParams<ThunderbirdApp>();

class ThunderbirdApp : public MooseApp
{
public:
  ThunderbirdApp(InputParameters parameters);
  virtual ~ThunderbirdApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* THUNDERBIRDAPP_H */
