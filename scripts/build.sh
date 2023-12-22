echo "pwd: $PWD"

arduino-cli compile -b arduino:avr:mega app --build-path ./build \
--library "./app/lib/app" \
--library "./app/lib/controls" \
--library "./app/lib/utils" \
-v
echo "build complete."
