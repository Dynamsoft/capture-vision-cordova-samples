document.addEventListener('deviceready', onDeviceReady, false)

async function onDeviceReady() { 
    console.log('Running cordova-' + cordova.platformId + '@' + cordova.version);
    document.getElementById('deviceready').classList.add('ready');

    if (!window.localStorage.initLicense) { 
        // Initialize license for the Barcode Decoding module of Dynamsoft Capture Vision.
	    // The license string here is a time-limited trial license. Note that network connection is required for this license to work.
	    // You can also request an extension for your trial license in the customer portal: https://www.dynamsoft.com/customer/license/trialLicense?product=dbr&utm_source=installer&package=cordova
        try {
            await Dynamsoft.DCVBarcodeReader.initLicense("DLS2eyJvcmdhbml6YXRpb25JRCI6IjIwMDAwMSJ9");
        } catch (e) {
            console.log(e)
        }
        window.localStorage.initLicense = true;
    }
}