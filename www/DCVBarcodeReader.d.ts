import { BarcodeResult } from './BarcodeResult';
import { DBRRuntimeSettings, EnumDBRPresetTemplate } from './BarcodeSettings';
export declare class DCVBarcodeReader {
    private constructor();
    static createInstance(): Promise<DCVBarcodeReader>;
    static initLicense(license: String): Promise<void>;
    static getVersion(): Promise<String>;
    startScanning(): void;
    stopScanning(): void;
    addResultListener(listener: (results: BarcodeResult[]) => void): void;
    getRuntimeSettings(): Promise<DBRRuntimeSettings>;
    outputSettingsToString(): Promise<String>;
    updateRuntimeSettings(settings: String | DBRRuntimeSettings | EnumDBRPresetTemplate): Promise<void>;
    resetRuntimeSettings(): void;
}
