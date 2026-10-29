package com.openfgclone.companion

import android.app.Service
import android.content.Intent
import android.os.IBinder

class FloatingService : Service() {
    override fun onBind(intent: Intent?): IBinder? = null
}
