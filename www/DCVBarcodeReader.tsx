import exec from 'cordova/exec';
import { BarcodeResult } from './BarcodeResult';
import { DBRRuntimeSettings, EnumDBRPresetTemplate } from './BarcodeSettings';

export class DCVBarcodeReader {
    private constructor() {
    }

    /**
    * Create an instance of the DCVBarcode reader.
    */ 
    static createInstance(): Promise<DCVBarcodeReader> {
        let promise: Promise<DCVBarcodeReader> = new Promise(function (resolve, reject) {
            exec(() => {
                resolve(new DCVBarcodeReader())
            }, (error: String) => {
                reject(error)
            }, 'DynamsoftCordovaPlugin', 'createDbrInstance', []);
        })
        return promise
    }

    /**
    * Initialize the license with a license key.
    */
    static initLicense (license: String): Promise<void> {
        let promise: Promise<void> = new Promise(function (resolve, reject) {
            exec(
            ()=>resolve()
            , (error: String) => {
                reject(error)
            }, 'DynamsoftCordovaPlugin', 'initLicense', [license])
        })
        
        return promise;
    }

    /**
    * Get the version of the barcode reader library.
    */
    static getVersion(): Promise<String> {
        let promise: Promise<String> = new Promise(function (resolve, reject) {
            exec((version: String) => {
                resolve(version)
            }, null, 'DynamsoftCordovaPlugin', 'getVersion', []);
        })
        return promise;
    }

    /**
    * Start barcode decoding from the video streaming.
    */
    startScanning() {
        exec(null, null, 'DynamsoftCordovaPlugin', 'startScanning', []);
    }

    /**
    * Stop barcode decoding from the video streaming.
    */
    stopScanning() {
        exec(null, null, 'DynamsoftCordovaPlugin', 'stopScanning', []);
    }

    /**
    * Register a listener to receive callback when barcode result is output.
    */
    addResultListener(listener: (results: BarcodeResult[]) => void) {
        exec(listener, null, 'DynamsoftCordovaPlugin', 'setTextResultListener', []);
    }

    /**
    * Get the current runtime settings as a DBRRuntimeSettings object.
    */
    getRuntimeSettings(): Promise<DBRRuntimeSettings> {
        let promise: Promise<DBRRuntimeSettings> = new Promise(function (resolve, reject) {
            exec((settings: DBRRuntimeSettings) => {
                resolve(settings);
            }, (error: String) => {
                reject(error);
            }, 'DynamsoftCordovaPlugin', 'getRuntimeSettings', []);
        })
        return promise
    }

    /**
    * Output the current runtime settings as a string.
    */
    outputSettingsToString() : Promise<String> {
        let promise: Promise<String> = new Promise(function (resolve, reject) {
            exec((msg: String) => {
                resolve(msg);
            }, (msg: String) => {
                reject(msg);
            }, 'DynamsoftCordovaPlugin', 'outputSettingsToString', []);
        })
        return promise
    }

    /**
    * Update the current runtime settings with a DBRRuntimeSettings object / a preset template / a JSON string.
    */
    updateRuntimeSettings(settings :String | DBRRuntimeSettings | EnumDBRPresetTemplate) : Promise<void> {
        let promise: Promise<void> = new Promise(function (resolve, reject) {
            exec(()=>resolve(), (msg: String) => {
                reject(msg);
            }, 'DynamsoftCordovaPlugin', 'updateRuntimeSettings', [settings]);
        })
        return promise
    }

    /**
    * Reset the runtime settings.
    */
    resetRuntimeSettings() {
        exec(null, null, 'DynamsoftCordovaPlugin', 'resetRuntimeSettings', []);
    }
}




