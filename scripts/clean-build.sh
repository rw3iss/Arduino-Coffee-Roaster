arduino-cli compile -b arduino:avr:mega app --clean --build-path ./build \
--library "./app" \
--library "./app/src" \
--library "./app/lib" \
--library "./app/lib/app" \
--library "./app/lib/controls" \
--library "./app/lib/utils"
echo "clean-build complete."