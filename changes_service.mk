PRODUCT_PACKAGES += devtempstats_service

BOARD_SEPOLICY_DIRS += device/stats_silviu/sepolicy \
                       device/stats_silviu/sepolicy/example_service

LOCAL_SHARED_LIBRARIES += devtempstats.service.api

DEVICE_MANIFEST_FILE += device/stats_silviu/manifests/manifest.xml
DEVICE_FRAMEWORK_COMPATIBILITY_MATRIX_FILE += device/stats_silviu/manifests/framework_compatibility_matrix.xml