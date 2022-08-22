import exec from 'cordova/exec';
import { BarcodeResult } from './BarcodeResult';
import { DBRRuntimeSettings, EnumDBRPresetTemplate } from './BarcodeSettings';

export class DCVBarcodeReader {
    private constructor() {
    }

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

    static getVersion(): Promise<String> {
        let promise: Promise<String> = new Promise(function (resolve, reject) {
            exec((version: String) => {
                resolve(version)
            }, null, 'DynamsoftCordovaPlugin', 'getVersion', []);
        })
        return promise;
    }

    startScanning() {
        exec(null, null, 'DynamsoftCordovaPlugin', 'startScanning', []);
    }
    stopScanning() {
        exec(null, null, 'DynamsoftCordovaPlugin', 'stopScanning', []);
    }
    addResultListener(listener: (results: BarcodeResult[]) => void) {
        exec(listener, null, 'DynamsoftCordovaPlugin', 'setTextResultListener', []);
    }

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

    updateRuntimeSettings(settings :String | DBRRuntimeSettings | EnumDBRPresetTemplate) : Promise<void> {
        let promise: Promise<void> = new Promise(function (resolve, reject) {
            exec(()=>resolve(), (msg: String) => {
                reject(msg);
            }, 'DynamsoftCordovaPlugin', 'updateRuntimeSettings', [settings]);
        })
        return promise
    }

    resetRuntimeSettings() {
        exec(null, null, 'DynamsoftCordovaPlugin', 'resetRuntimeSettings', []);
    }
}




