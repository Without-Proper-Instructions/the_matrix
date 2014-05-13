#!/bin/bash
set -x

# Directories to copy into the matrix
# TODO:  use / with exclude list
MATRIX_SRC="/bin /boot /etc /lib /lib64 /mnt /opt /root /run /sbin /srv /tmp /usr /var"

# Destination directory
MATRIX_DST=/matrix-again

mkdir -pv ${MATRIX_DST}

# Copy the root filesystem to the matrix dir
cp -pRl ${MATRIX_SRC} ${MATRIX_DST} #> ~/cp-status 2>&1

# Mount kernel/device filesystems
mkdir -pv ${MATRIX_DST}/{dev,proc,sys}
mount -o bind  /dev ${MATRIX_DST}/dev
mount -t proc  none ${MATRIX_DST}/proc
mount -t sysfs none ${MATRIX_DST}/sys
