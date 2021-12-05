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

# region : VECTOR
cc_library(
    name = "segment-utils",
    srcs = ["test_utils/segment_utils.cc"],
    hdrs = ["test_utils/segment_utils.h"],
    deps = [
        "point-utils",
        "//main:primitives",
    ],
)

cc_test(
    name = "segment-test",
    size = "small",
    srcs = ["primitives/segment_test.cpp"],
    deps = [
        ":segment-utils",
        ":testing",
        "@com_google_googletest//:gtest_main"
    ],
    # args = ["--gtest_repeat=1000", "--gtest_break_on_failure"]
)
# endregion

# region : POLYGON
cc_library(
    name = "polygon-utils",
    srcs = ["test_utils/polygon_utils.cc"],
    hdrs = ["test_utils/polygon_utils.h"],
    deps = [
        "point-utils",
        "segment-utils",
        "//main:primitives",
    ],
)

cc_test(
    name = "polygon-test",
    size = "small",
    srcs = ["primitives/polygon_test.cc"],
    deps = [
        ":polygon-utils",
        ":testing",
        "@com_google_googletest//:gtest_main"
    ],
    # args = ["--gtest_repeat=1000", "--gtest_break_on_failure"]
)
# endregion