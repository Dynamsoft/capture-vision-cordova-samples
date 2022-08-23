document.addEventListener('deviceready', onDeviceReady, false)

async function onDeviceReady() { 
    console.log('Running cordova-' + cordova.platformId + '@' + cordova.version);
    document.getElementById('deviceready').classList.add('ready');

    if (!window.localStorage.initLicense) { 
        try {
            await Dynamsoft.DCVBarcodeReader.initLicense("DLS2eyJvcmdhbml6YXRpb25JRCI6IjIwMDAwMSJ9");
        } catch (e) {
            console.log(e)
        }
        window.localStorage.initLicense = true;
    }
}