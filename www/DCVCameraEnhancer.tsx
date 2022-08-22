import exec from 'cordova/exec';
import { Region } from './BasicStructures';

enum EnumTorchState {
    OFF,
    ON
}

export class DCVCameraEnhancer {
    

    private constructor() { 
        
    }

    static createInstance(): Promise<DCVCameraEnhancer> {
        let promise: Promise<DCVCameraEnhancer> = new Promise(function (resolve, reject) {
            exec(() => {
                resolve(new DCVCameraEnhancer())
            }, null, 'DynamsoftCordovaPlugin', 'createDceInstance', []);
        })
        return promise
    }

    

    open(): Promise<void> {
        let promise: Promise<void> = new Promise(function (resolve, reject) {
            exec(()=>resolve(), (error:String)=>reject(error), 'DynamsoftCordovaPlugin', 'open', []);
        })
        return promise
    }

    close(): Promise<void> {
        let promise: Promise<void> = new Promise(function (resolve, reject) {
            exec(()=>resolve(), (error:String)=>reject(error), 'DynamsoftCordovaPlugin', 'close', []);
        })
        return promise
    }

    

    turnOnTorch(): Promise<void> {
        let promise: Promise<void> = new Promise(function (resolve, reject) {
            exec(()=>resolve(), (error:String)=>reject(error), 'DynamsoftCordovaPlugin', 'setTorchState', [EnumTorchState.ON]);
        })
        return promise
    }

    turnOffTorch(): Promise<void> {
        let promise: Promise<void> = new Promise(function (resolve, reject) {
            exec(()=>resolve(), (error:String)=>reject(error), 'DynamsoftCordovaPlugin', 'setTorchState', [EnumTorchState.OFF]);
        })
        return promise
    }

    

    setScanRegion(region: Region): Promise<void> {
        if (region) {
            region.regionMeasuredByPercentage = region.regionMeasuredByPercentage ? 1 : 0;
        }
        let promise: Promise<void> = new Promise(function (resolve, reject) {
            exec(()=>resolve(), (error:String)=>reject(error), 'DynamsoftCordovaPlugin', 'setScanRegion', [region]);
        })
        return promise
    }

    setScanRegionVisible(isVisible: boolean) {
        exec(null, null, 'DynamsoftCordovaPlugin', 'setScanRegionVisible', [isVisible]);
    }

   
}

