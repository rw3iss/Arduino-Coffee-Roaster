echo "pwd: $PWD"

arduino-cli compile -b arduino:avr:mega app --build-path ./build \
--library "./app/src" \
--library "./app/lib/app" \
--library "./app/lib/controls" \
--library "./app/lib/utils" \
--library "./app/lib/app/views" \
--library "./app/lib/app/views/components" \
--library "./app/config" \
--library "./lib/OneButton" \
-v
echo "build complete."
