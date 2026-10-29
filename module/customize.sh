#!/system/bin/sh
SKIPUNZIP=0

CONFIG_DIR=/data/adb/openfg_clone
mkdir -p "$CONFIG_DIR"
: > "$CONFIG_DIR/packages.list"
set_perm_recursive "$CONFIG_DIR" 0 0 0755 0644

ui_print "- OpenFG Clone installed"
ui_print "- Configure in companion app"
