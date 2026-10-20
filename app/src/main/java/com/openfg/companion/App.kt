package com.openfg.companion

import android.app.Application

class App : Application() {
    override fun onCreate() {
        super.onCreate()
        // TODO: root shell via libsu, read/write /data/adb/openfg/packages.list
    }
}
