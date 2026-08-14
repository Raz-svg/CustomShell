#!/bin/sh
set -e

REPO_DIR="$(cd "$(dirname "$0")" && pwd)"

(
  cd "$REPO_DIR"

  cmake -B build -S . \
    -G "Ninja" \
    -DCMAKE_C_COMPILER=clang \
    -DCMAKE_CXX_COMPILER=clang++

  cmake --build build
)

if [ -f "$REPO_DIR/build/shell.exe" ]; then
  exec "$REPO_DIR/build/shell.exe" "$@"
elif [ -f "$REPO_DIR/build/shell" ]; then
  exec "$REPO_DIR/build/shell" "$@"
else
  echo "Error: binary not found in build/" >&2
  exit 1
fi
