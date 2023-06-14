# Ready Player Me Web Browser

![Screenshot 2022-10-26 121009](https://user-images.githubusercontent.com/108666572/198000086-7771d6a5-70cc-4b39-b087-b0533257d9be.png)

![Screenshot 2022-10-26 121106](https://user-images.githubusercontent.com/108666572/198000119-79ea06ea-4a12-458d-8c7d-88cf7d7ab208.png)

Ready Player Me Web Browser is an extension to www.readyplayer.me avatar platform, which helps you to open integrated web browser at runtime.

RpmWebBrowser plugin uses the Unreal Engine Web Browser module (and Web Browser Widget) to embed the Ready Player Me Web Avatar Creator inside an application.

Please visit the online documentation and join our public `discord` community.

![](https://i.imgur.com/zGamwPM.png) **[Online Documentation]( https://docs.readyplayer.me/ready-player-me/integration-guides/unreal-sdk )**

![](https://i.imgur.com/FgbNsPN.png) **[Discord Channel]( https://discord.gg/9veRUu2 )**

## Constraints

**NOTE:** The Web Browser module will only work with our readyplayer.me website in Unreal Engine 5 on Windows platform. The Web Browser module in Unreal Engine 4 uses a very old version of chromium which does not support all the modern web browser features.

## Requirements

- Unreal Engine Version 5.0 or higher

## Integration

### Add RpmWebBrowser plugin

There are three ways you can add the **RpmAvatarCreator** plugin to your project. Add as submodules, paste the plugin inside of the **Plugins** folder, or add the blueprint version of the plugin to the Engine.

- To add the plugin to your project as a submodules, run the following command in the terminal from your project folder. This is preferred way of setting up the plugin.

  ```
   git submodule add --name Plugins/RpmWebBrowser -- https://github.com/readyplayerme/rpm-unreal-web-browser.git Plugins/RpmWebBrowser
  ```

- To clone the plugin into your project, run the following command in the terminal from your project folder.

- To paste the plugin inside of the Plugins folder, create a **Plugins** folder from the root of your project, download the latest tags of the [RpmWebBrowser](https://github.com/readyplayerme/rpm-unreal-web-browser.git) plugin into it. Rename the **rpm-unreal-web-browser** plugin folder to the **RpmWebBrowser**.

- To add the blueprint version of the plugin, find the plugin attached in the [Latest Release](https://github.com/readyplayerme/rpm-unreal-web-browser/releases/latest), add it to the Plugins/Runtime folder of the installed Unreal Engine.

### Update RpmWebBrowser plugin submodule

To update the plugin submodule paste the following command in the terminal from your project folder. This will fetch and switch the plugin repositories to the latest stable release.

  ```
  cd Plugins/RpmWebBrowser ; git fetch --tags ; git checkout $(git describe --tags $(git rev-list --tags --max-count=1)) ; cd ../..
  ```

## Quick Start

A demo map is included in the plugin for demonstrating how the **Sample Avatar Creator** opens at runtime. It is located in the `RpmAvatarCreator\Content\Maps` folder.
To add the AvatarCreator widget to your project simply copy the existing blueprint logic from the demo map into your project.

**RpmAvatarCreatorWidget** is a widget that can be added to a map or another widget.
Inside the WebBrowserDemo map we create and add the widget to the viewport.
**AvatarCreator** can be customized by providing default values when the widget is created.
We need to subscribe to the **Avatar Saved** event to get the URL when the avatar is saved.
We need to subscribe to the **Avatar Selected** event as well to get the URL when the avatar is selected from the list of user avatars.
Additionally, we can load an avatar with this URL afterward.

![Screenshot_20230221_060932](https://user-images.githubusercontent.com/3124894/229149539-1ae0e7a5-c9ae-4671-b6e1-e267e14fd204.png)

Additionally if close button is enabled, we can subscribe to the **Close Button Clicked** event to be notified when the close button is clicked.
This way we can close the widget and perform other actions.

# Web Browser Demo Map

The WebBrowserDemo map located in the `Content` folder is a good starting point for anybody wanting to use the Web Browser plugin to seamlessly integrate our RPM Web Avatar Creator into you game or application.
The logic for this is rather simple, if you open up the Level Blueprint you will see this network of nodes.

![Screenshot 2022-10-26 122813](https://user-images.githubusercontent.com/108666572/198003565-c192c23d-9d34-4b10-ac4b-783bc1db4061.png)

In the first group of nodes, connected to the `BeginPlay` event we create and add our Ready Player Me Browser widget to the viewport before setting `ShowMouseCursor` to true so that the user can see the cursor and interact with the browser widget.

![Screenshot 2022-10-26 122603](https://user-images.githubusercontent.com/108666572/198003525-3be3ec33-c514-4945-8c85-ea3250e92564.png)

Next we bind the RPM Browser widget's Avatar Generated Event to run the Load New Avatar event on a RPM Actor blueprint present in the map. The Avatar Generated Event is called from the web browser widget once the avatar creation process is complete and it returns a URL to the RPM avatar GLB file, which we subsequently load into the scene.

![Screenshot 2022-10-26 122603](https://user-images.githubusercontent.com/108666572/198003202-25142a00-e7ee-4077-9c3c-9f26cd12a43d.png)

# Web Browser Wrapper Widget

`WBP_RPM_WebBrowserWrapper` widget is a helper widget, that demonstrates the usage of the RpmWebBrowserWidget widget. 
It's located in `Content > Widgets`. If you open up the widget you will in the Hierarchy panel that it consists of a **RPM Web Browser widget** inside of it.

![img-widget-hierarchy](https://user-images.githubusercontent.com/7085672/163364100-75cc563b-3e78-418f-ab1a-47b79cfabf45.png)

The helper widget adds padding to the `RpmWebBrowser` widget. It also adds listeners for the `RpmWebBrowser` events.

![Screenshot 2023-06-08 110605](https://github.com/readyplayerme/UnrealExamples/assets/7085672/094e98ca-733c-44cc-b582-32ab00e84e51)

**Avatar Exported** callback section which shows the `OnAvatarExported` event we mentioned previous. Use this callback and the AvatarUrl property to retrieve the avatar url.
![Screenshot 2023-06-08 123434](https://github.com/readyplayerme/UnrealExamples/assets/7085672/44043a1e-7a2d-4974-a4d8-fffea13a5c4b)

## Avatar Creator Customization

RpmWebBrowserWidget widget has properties that can be tweaked to customize the avatar creator. By changing the parameters a custom Url will be generated for the web browser.
- **Partner Domain**: By default it's set to demo, however as the name suggests this is only recommended for demo's. We highly recommend you become a Ready Player Me partner and get your own partner space. Once you have your own partner space setup you update this parameter accordingly.
- **Clean Cache**: Provides a Kiosk experience
- **Quick Start**: Enters the Quick Start view.
- **Body Type**: Skip the body type selection step when opening the avatar view.
- **Gender**: Skip the gender selection step when opening the avatar view.
- **Language**: By default the system language will be used for opening the browser, However the language can be customized.

![Screenshot 2022-12-02 173148](https://user-images.githubusercontent.com/3124894/205340278-cc75a168-7813-4e32-bfdb-e44e41f00555.png)

## Subscribe To Events

Further down in the Details panel you will see a number of events that can be bound to.
These events are called from the **WebBrowser Widget** when certain events occur.
For example when the avatar creation process has been completed the `OnAvatarExported` event will be called.
This event will return the URL to the GLB file of the avatar. This can then be used to load the avatar into the scene.

![Screenshot 2023-06-08 110535](https://github.com/readyplayerme/UnrealExamples/assets/7085672/1716ab37-a550-44af-966d-e31d12a46d32)

# Ready Player Me Browser Widget Class

The `URpmWebBrowserWidget` class, is inherited from the Unreal` UWebBrowser` class and it adds a few extra functions for setting up the connection between the Web Browser and **Ready Player Me** website.

It adds delegates for the events that are thrown from the **Ready Player Me** avatar creator web page.
The following delegates are available for subscription: 
- OnAvatarExported
- OnUserSet
- OnAssetUnlock
- OnUserAuthorized

## Links
- [Documentation](https://docs.readyplayer.me/ready-player-me/integration-guides/unreal-engine)
- [Support](https://docs.readyplayer.me/ready-player-me/integration-guides/unreal-engine/troubleshooting)
