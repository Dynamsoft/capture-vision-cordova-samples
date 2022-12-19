import exec from 'cordova/exec';
import { Region } from './BasicStructures';

enum EnumTorchState {
    OFF,
    ON
}

export class DCVCameraEnhancer {
    

    private constructor() { 
        
    }

    /**
    * Create an instance of DCVCameraEnhancer.
    */
    static createInstance(): Promise<DCVCameraEnhancer> {
        let promise: Promise<DCVCameraEnhancer> = new Promise(function (resolve, reject) {
            exec(() => {
                resolve(new DCVCameraEnhancer())
            }, null, 'DynamsoftCordovaPlugin', 'createDceInstance', []);
        })
        return promise
    }

    /**
    * Open the camera.
    */
    open(): Promise<void> {
        let promise: Promise<void> = new Promise(function (resolve, reject) {
            exec(()=>resolve(), (error:String)=>reject(error), 'DynamsoftCordovaPlugin', 'open', []);
        })
        return promise
    }

    /**
    * Close the camera.
    */
    close(): Promise<void> {
        let promise: Promise<void> = new Promise(function (resolve, reject) {
            exec(()=>resolve(), (error:String)=>reject(error), 'DynamsoftCordovaPlugin', 'close', []);
        })
        return promise
    }

    /**
    * Trun on the torch.
    */
    turnOnTorch(): Promise<void> {
        let promise: Promise<void> = new Promise(function (resolve, reject) {
            exec(()=>resolve(), (error:String)=>reject(error), 'DynamsoftCordovaPlugin', 'setTorchState', [EnumTorchState.ON]);
        })
        return promise
    }

    /**
    * Trun off the torch.
    */
    turnOffTorch(): Promise<void> {
        let promise: Promise<void> = new Promise(function (resolve, reject) {
            exec(()=>resolve(), (error:String)=>reject(error), 'DynamsoftCordovaPlugin', 'setTorchState', [EnumTorchState.OFF]);
        })
        return promise
    }

    /**
    * Specify a region of interest with a region object.
    */
    setScanRegion(region: Region): Promise<void> {
        if (region) {
            region.regionMeasuredByPercentage = region.regionMeasuredByPercentage ? 1 : 0;
        }
        let promise: Promise<void> = new Promise(function (resolve, reject) {
            exec(()=>resolve(), (error:String)=>reject(error), 'DynamsoftCordovaPlugin', 'setScanRegion', [region]);
        })
        return promise
    }

    /**
    * Set whether to display the scan region.
    */
    setScanRegionVisible(isVisible: boolean) {
        exec(null, null, 'DynamsoftCordovaPlugin', 'setScanRegionVisible', [isVisible]);
    }

   
}

