package com.openfgclone.companion

import com.topjohnwu.superuser.Shell

class RootConfig {
    companion object {
        const val DIR = "/data/adb/openfg_clone"
        const val FILE = "$DIR/packages.list"
    }
    
    fun writeToggle(packageName: String, key: String, value: String): Boolean {
        // Write to /data/user/*/packageName/files/ like OpenFG does
        val cmd = """
            wrote=0
            for d in /data/user/*/$packageName; do
                [ -d "\$d" ] || continue
                fdir="\$d/files"
                mkdir -p "\$fdir"
                echo -n '$value' > "\$fdir/$key"
                chmod 644 "\$fdir/$key"
                wrote=1
            done
            [ "\$wrote" = 1 ]
        """
        val result = Shell.cmd(cmd.trimIndent()).exec()
        return result.isSuccess
    }
}
