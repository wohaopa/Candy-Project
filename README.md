# Candy - Plug-in development experimental framework Based on Qt

All module functionality is a plug-in. They become less dependent on each other. Sometimes we don't need to relate to
the implementation details of a feature, we just need to publish an event to get the results we need.

**If you are interested in this project and would like to contact me, I would be happy to accompany you**

## Structure

All functionality is wrapped into modules, and one or more modules are composed into components. The modules inside a
component may be strongly dependent or weakly dependent; we don't care.

Plugins can provide more modules to one or more components or modify the functionality of a module by using its API.

### Components to be developed

1. **Core** - A core component of the Candy framework that provides many of the basic features of the Candy framework.
    1. **Daemon** The daemon module, which provides a global thread for the signal slot object, on which non-view
       tasks are processed.
    2. **Cache** A global cache module, with permission management, is used to pass data within the framework.
    3. **Task** Task modules, the basis of Candy design, all features are tasks.
    4. **EventBus** It is used to handle communication between modules and is the basis for API design.
    5. **Manager** Component management, loading and unloading updates handle other components.
    6. **Plugin** Plugin Manager.
    7. **Config** A configuration module that manages the configuration items of each component.
    8. **Log** Logging module.
2. **View** View components, which provide basic view functionality.
    1. **ViewManager**
    2. **QMLLoader**
    3. **Theme**
    4. **Translate**
    5. **Views**
3. **FileExplorer**
4. **Git**
5. **RemoteDemo**

