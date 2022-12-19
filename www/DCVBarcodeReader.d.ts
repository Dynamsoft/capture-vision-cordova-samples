import { BarcodeResult } from './BarcodeResult';
import { DBRRuntimeSettings, EnumDBRPresetTemplate } from './BarcodeSettings';
export declare class DCVBarcodeReader {
    private constructor();
    /**
    * Create an instance of the DCVBarcode reader.
    */
    static createInstance(): Promise<DCVBarcodeReader>;
    /**
    * Initialize the license with a license key.
    */
    static initLicense(license: String): Promise<void>;
    /**
    * Get the version of the barcode reader library.
    */
    static getVersion(): Promise<String>;
    /**
    * Start barcode decoding from the video streaming.
    */
    startScanning(): void;
    /**
    * Stop barcode decoding from the video streaming.
    */
    stopScanning(): void;
    /**
    * Register a listener to receive callback when barcode result is output.
    */
    addResultListener(listener: (results: BarcodeResult[]) => void): void;
    /**
    * Get the current runtime settings as a DBRRuntimeSettings object.
    */
    getRuntimeSettings(): Promise<DBRRuntimeSettings>;
    /**
    * Output the current runtime settings as a string.
    */
    outputSettingsToString(): Promise<String>;
    /**
    * Update the current runtime settings with a DBRRuntimeSettings object / a preset template / a JSON string.
    */
    updateRuntimeSettings(settings: String | DBRRuntimeSettings | EnumDBRPresetTemplate): Promise<void>;
    /**
    * Reset the runtime settings.
    */
    resetRuntimeSettings(): void;
}
