import { Region } from './BasicStructures';
export declare class DCVCameraEnhancer {
    private constructor();
    /**
    * Create an instance of DCVCameraEnhancer.
    */
    static createInstance(): Promise<DCVCameraEnhancer>;
    /**
    * Open the camera.
    */
    open(): Promise<void>;
    /**
    * Close the camera.
    */
    close(): Promise<void>;
    /**
    * Trun on the torch.
    */
    turnOnTorch(): Promise<void>;
    /**
    * Trun off the torch.
    */
    turnOffTorch(): Promise<void>;
    /**
    * Specify a region of interest with a region object.
    */
    setScanRegion(region: Region): Promise<void>;
    /**
    * Set whether to display the scan region.
    */
    setScanRegionVisible(isVisible: boolean): void;
}
