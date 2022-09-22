# Dynamsoft Capture Vision Cordova Edition

Dynamsoft Capture Vision (DCV) is an aggregating SDK of a series of specific functional products including:

- Dynamsoft Camera Enhancer (DCE) which provides camera enhancements and UI configuration APIs.
- Dynamsoft Barcode Reader (DBR) which provides barcode decoding algorithm and APIs.
- Dynamsoft Label Recognizer (DLR) which provides label content recognizing algorithm and APIs.
- Dynamsoft Document Normalizer (DDN) which provides document scanning algorithms and APIs.

> Note: DCV Cordova edition currently only includes DCE and DBR modules. DLR and DDN modules are still under development and will be included in the future.

## Table of Contents

- [System Requirements](#system-requirements)
- [Installation](#installation)
- [Build Your Barcode Scanner App](#build-your-barcode-scanner-app)
  - [Set up Development Environment](#set-up-development-environment)
  - [Initialize the Project](#initialize-the-project)
  - [Include the Library](#include-the-library)
  - [Initialize the License](#initialize-the-license)
  - [Initialize the Camera Module](#initialize-the-camera-module)
  - [Configure the Barcode Reader Module](#configure-the-barcode-reader-module)
  - [Run the Project](#run-the-project)
- [Samples](#samples)
- [API References](#api-references)
- [License](#license)
- [Contact](#contact)

## System Requirements

### Cordova Platforms

- Cordova Android: 10.1.1+
- Cordova iOS: 6.2.0

### Android

- Supported OS: Android 5.0 (API Level 21) or higher.
- Supported ABI: **armeabi-v7a**, **arm64-v8a**, **x86** and **x86_64**.
- Development Environment: Android Studio 3.4+ (Android Studio 4.2+ recommended).
- JDK: 1.8+

### iOS

- Supported OS: **iOS 11.0** or higher.
- Supported ABI: **arm64** and **x86_64**.
- Development Environment: Xcode 7.1 and above (Xcode 13.0+ recommended), CocoaPods 1.11.0+.

## Installation

- **Github**

```bash
cordova plugin add https://github.com/Dynamsoft/capture-vision-cordova
```

- **npm**

```bash
cordova plugin add dynamsoft-capture-vision-cordova
```

## Build Your Barcode Scanner App

Now you will learn how to create a simple barcode scanner using Dynamsoft Capture Vision for Cordova.

>Note: Instead of following this guide, you can also initialize a project with this template to get started: <a href="https://github.com/Dynamsoft/capture-vision-cordova-samples/tree/main/BarcodeReaderSimpleSample" target="_blank">Barcode Reader Simple Sample</a>.

### Set up Development Environment

If you are a beginner with Cordova, please follow the guide on the <a href="https://cordova.apache.org/docs/en/11.x/guide/cli/index.html" target="_blank">Cordova official website</a> to set up the development environment.

### Initialize the Project

Use the following command to create a new project.

```bash
cordova create SimpleBarcodeScanner
```

### Include the Library

Use the following command to include the library.

```bash
cordova plugin add dynamsoft-capture-vision-cordova
```

### Initialize the License

The Barcode Reader module of Dynamsoft Capture Vision needs a valid license to work. Add the following code in **www/index.js** to initialize the license of the Barcode Reader module

```js
// Register the event of device ready.
document.addEventListener('deviceready', onDeviceReady, false)

async function onDeviceReady() {
    ...
    // Here we use a public trial key as an example.
    try {
        await Dynamsoft.DCVBarcodeReader.initLicense("DLS2eyJvcmdhbml6YXRpb25JRCI6IjIwMDAwMSJ9")
    } catch (e) {
        console.log(e)
    }
}
```

### Initialize the Camera Module

Dynamsoft Capture Vision provides a build-in camera module for you to capture and display the video stream. The following two classes are used when initializing the camera module:

- [`DCVCameraEnhancer`](../api-reference/camera-enhancer.md): The class that provides camera controlling APIs. Please visit the link to learn more.
- [`DCVCameraView`](../api-reference/camera-view.md): The camera view that will display the video stream and other UI elements. Please visit the link to learn more.

1. Find the **www/index.html** file in your project. Replace the original content with the following code:

    ```html
    <!DOCTYPE html>
    <html>
        <body style="margin: 0;">
            <div id="camera_view" style="width: 100vw; height: 100vh; z-index: -1;">
                <div id="show_result" style="position: fixed; width: 100vw; bottom: 10vh;  text-align:center; color: white; "></div>
            </div>
            <script src="cordova.js"></script>
            <script src="js/index.js"></script>
        </body>
    </html>
    ```

2. Open **www/index.js** and add code to initialize `DCVCameraEnhancer` and `DCVCameraView`

    ```js
    var dcvCameraEnhancer
    // Get the camera_view <div> we created in the previous step.
    const cameraViewElement = document.getElementById("camera_view")

    async function onDeviceReady() {
        // Create the instance of DCVCameraEnhancer.
        dcvCameraEnhancer = await Dynamsoft.DCVCameraEnhancer.createInstance()
        // Create the instance of DCVCameraView.
        var cameraView = new Dynamsoft.DCVCameraView()
        // Bind the instance of DCVCameraView with the div you created before.
        cameraView.bindToHtmlElement(cameraViewElement)
        // Display overlays on the detected barcodes.
        cameraView.setOverlayVisible(true)
    }
    ```

### Configure the Barcode Reader Module

1. Initialize the barcode reader module. Register a result listener for obtaining the barcode results.

    ```js
    ...
    var dcvBarcodeReader
    async function onDeviceReady() {
        ...
        // Create the instance of DCVBarcodeReader.
        dcvBarcodeReader = await Dynamsoft.DCVBarcodeReader.createInstance()
        dcvBarcodeReader.addResultListener((results) => {
            const resultElement = document.getElementById('show_result')
            var resultStr = ""
            if (results && results.length > 0) {
                for (i = 0; i < results.length; i++) {
                    resultStr=resultStr + results[i].barcodeFormatString+":"+results[i].barcodeText+'\n'
                }
                resultElement.innerHTML = (resultStr)
            } else {
                resultElement.innerHTML = "No barcode detected in this frame."
            }
            document.querySelector('#camera_view').appendChild(resultElement)
        })
    }
    ```

2. Open the camera and start barcode scanning. You will receive the barcode results from the result listener.

    ```js
    async function onDeviceReady() {
        ...
        dcvCameraEnhancer.open()
        dcvBarcodeReader.startScanning()
    }
    ```

3. Register the event listeners `onResume` and `onPasue` so that the library can stop/restart barcode decoding when the user pauses or resumes the feature.

    ```js
    document.addEventListener('resume', onResume, false)
    document.addEventListener('pause', onPause, false)

    ...

    function onResume() {
        dcvCameraEnhancer.open()
        dcvBarcodeReader.startScanning()
    }

    function onPause() {
        dcvCameraEnhancer.close()
        dcvBarcodeReader.stopScanning()
    }
    ```

### Run the Project

#### Run Android on Windows or macOS

1. Add the platform first with the following command.

    ```bash
    cordova platform add android
    ```

2. Run the Project with the following command.

    ```bash
    cordova run android
    ```

#### Run iOS on macOS

1. Add the platform first.

    ```bash
    cordova platform add ios
    ```

2. Open the **platforms/ios/SimpleBarcodeScanner.xcworkspace** with xcode. Complete the *Signing & Capabilities* section of the project configuration via Xcode to avoid any signature errors during build.

## Samples

You can view all the DCV Cordova samples via the following links:

- <a href = "https://github.com/Dynamsoft/capture-vision-cordova-samples/tree/main/BarcodeReaderSimpleSample" target = "_blank" >Barcode reader simple sample</a>

## API References

View the API reference of DCV Cordova Edition to explore the full feature of DCV:

- <a href = "https://www.dynamsoft.com/capture-vision/docs/programming/cordova/api-reference/?ver=latest" target = "_blank" >DCV API Reference - Cordova Edition</a>
  - <a href = "https://www.dynamsoft.com/capture-vision/docs/programming/cordova/api-reference/barcode-reader.html?ver=latest" target = "_blank" >DCVBarcodeReader Class</a>
  - <a href = "https://www.dynamsoft.com/capture-vision/docs/programming/cordova/api-reference/camera-enhancer.html?ver=latest" target = "_blank" >DCVCameraEnhancer Class</a>
  - <a href = "https://www.dynamsoft.com/capture-vision/docs/programming/cordova/api-reference/camera-view.html?ver=latest" target = "_blank" >DCVCameraView Class</a>

## License

- A one-day trial license is available by default for every new device to try Dynamsoft Capture Vision.
- You can request an extension for your trial license in the <a href="https://www.dynamsoft.com/customer/license/trialLicense?product=dbr&package=mobile&utm_source=docs" target="_blank">customer portal</a>.

## Contact

https://www.dynamsoft.com/company/contact/
