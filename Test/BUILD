cc_library(
    name = "testing",
    srcs = ["testing.cpp"],
    hdrs = ["testing.h"],
    deps = ["@com_google_googletest//:gtest_main"],
)

cc_library(
    name = "common-utils",
    srcs = ["test_utils/common_utils.cpp"],
    hdrs = ["test_utils/common_utils.h"],
)

# region : POINT
cc_library(
    name = "point-utils",
    srcs = ["test_utils/point_utils.cpp"],
    hdrs = ["test_utils/point_utils.h"],
    deps = [
        "common-utils",
        "//main:primitives",
    ],
)

cc_test(
    name = "point-test",
    size = "small",
    srcs = ["primitives/point_test.cpp"],
    deps = [
        ":point-utils",
        ":testing",
    ],
)
# endregion

# region : VECTOR
cc_library(
    name = "vector-utils",
    srcs = ["test_utils/vector_utils.cc"],
    hdrs = ["test_utils/vector_utils.h"],
    deps = [
        "point-utils",
        "//main:primitives",
    ],
)

cc_test(
    name = "vector-test",
    size = "small",
    srcs = ["primitives/vector_test.cpp"],
    deps = [
        ":vector-utils",
        ":testing",
    ],
)
# endregion