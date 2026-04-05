#!/bin/bash
set -euo pipefail

# Usage function
usage() {
  cat <<EOF
Usage: $0 --test-exe <path/to/binary>

Obligatoire:
--test-exe    Path to the test binary to be executed with Qemu

Exemple:
$0 --test-exe ./build/tests/my_test.elf
EOF
  exit 1
}

# Check and parsing of arguments
if [ $# -ne 2 ] || [ "$1" != "--test-exe" ]; then
  usage
fi

readonly TEST_EXE="$2"
if [ ! -f "$TEST_EXE" ]; then
  echo "Erreur: Le fichier '$TEST_EXE' n'existe pas."
  usage
fi

# TODO : find simavr through CMake Find module
simavr -f 16000000 -m atmega328p "${TEST_EXE}" &
SIMAVR_PID="$!"
sleep 1
kill "${SIMAVR_PID}"

# Return in error. Test success or failure
# will be handled by CMAKE PASS_REGULAR_EXPRESSION
exit 255
