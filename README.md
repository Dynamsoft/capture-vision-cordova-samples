# Cordova Plugin with Dynamsoft Barcode Reader for iOS and Android
Use the Cordova plugin to quickly develop mobile barcode reader apps for iOS and Android. For more information, please visit http://www.dynamsoft.com/Products/Dynamic-Barcode-Reader.aspx.

## License
Get the [trial license](https://www.dynamsoft.com/CustomerPortal/Portal/Triallicense.aspx).

## Installation
1. Install **Cordova** vi **npm**:

    ```  
        npm install -g cordova
    ```

2. Download the source code and add the plugin via local path:

    ```
        cordova plugin add <local-path>/cordova-plugin-dbr
    ```

   Or, install the plugin via repo url directly:
    ```
        cordova plugin add https://github.com/dynamsoft-dbr/cordova-plugin-dbr.git
    ```

## Supported Platforms

- iOS
- Android

## Supported Barcode Types ##
The following barcode types are currently supported:

* Code 39
* Code 93
* Code 128
* Codabar
* EAN-8
* EAN-13
* UPC-A
* UPC-E
* Interleaved 2 of 5 (ITF)
* Industrial 2 of 5 (Code 2 of 5 Industry, Standard 2 of 5, Code 2 of 5)
* ITF-14 
* QRCode
* DataMatrix
* PDF417
## Others ##
If your cordova-android version >6.3.0, please change  repositories flatDir ``` dirs 'libs'  ``` to   ```dirs 'src/main/libs'  ``` and change  dependencies ``` compile 'com.android.support:support-v4:+'   ``` to   ```compile 'com.android.support:support-v4:27.1.0'  ```in flie [cordova-plugin-dbr/src/android/barcodescanner.gradle](https://github.com/dynamsoft-dbr/cordova-plugin-dbr/blob/master/src/android/barcodescanner.gradle) 


## Example

**index.html**

```html
<body>
        <div class="app">
            <div id="deviceready">
                <button id="scan">scan barcode</button>
            </div>
        </div>
        <script type="text/javascript" src="cordova.js"></script>
        <script type="text/javascript" src="js/index.js"></script>
    </body>
```

**index.js**

```js
   onDeviceReady: function() {
        document.getElementById("scan").onclick = function() {
                        cordova.plugins.barcodeScanner.scan(
                                                            function (result) {
                                                            alert("We got a barcode\n" +
                                                                  "Result: " + result.text + "\n" +
                                                                  "Format: " + result.format + "\n" +
                                                                  "Cancelled: " + result.cancelled);
                                                            },
                                                            function (error) {
                                                            alert("Scanning failed: " + error);
                                                            },
                                                            {
                                                            "preferFrontCamera" : false, // iOS and Android
                                                            "showFlipCameraButton" : true, // iOS and Android
                                                            "dynamsoftlicense": "your license ",//set the dynamsoftbarcodereader license
                                                            //"dynamsoftlicenseKey": "", //set the server license key
                                                            }
                                                            );
                    }
        this.receivedEvent('deviceready');
    },
```

## Technical Support
support@dynamsoft.com

## Screenshots
![Cordova barcode plugin](http://www.codepool.biz/wp-content/uploads/2018/04/IMG_2911.PNG)

![Cordova barcode plugin for PDF417](http://www.codepool.biz/wp-content/uploads/2018/04/IMG_2913.PNG)
