package com.openfgclone.companion

import com.topjohnwu.superuser.Shell

class RootConfig {
    companion object {
        const val DIR = "/data/adb/openfg_clone"
        const val FILE = "$DIR/packages.list"
    }

    fun writeToggle(packageName: String, key: String, value: String): Boolean {
        val cmd = "wrote=0\n" +
            "for d in /data/user/*/$packageName; do\n" +
            "  [ -d \"\$d\" ] || continue\n" +
            "  fdir=\"\$d/files\"\n" +
            "  mkdir -p \"\$fdir\"\n" +
            "  echo -n '$value' > \"\$fdir/$key\"\n" +
            "  chmod 644 \"\$fdir/$key\"\n" +
            "  wrote=1\n" +
            "done\n" +
            "[ \"\$wrote\" = 1 ]"
        val result = Shell.cmd(cmd).exec()
        return result.isSuccess
    }
}
