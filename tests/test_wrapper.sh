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

qemu-system-avr -machine uno -bios "${TEST_EXE}" -serial stdio -display none &
QEMU_PID="$!"
sleep 1
kill "${QEMU_PID}"

