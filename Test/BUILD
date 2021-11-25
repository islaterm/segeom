cc_library(
    name = "testing",
    srcs = ["Testing.cpp"],
    hdrs = ["Testing.h"],
    deps = ["@com_google_googletest//:gtest_main"],
)

cc_library(
    name = "common-utils",
    srcs = ["TestUtils/CommonUtils.cpp"],
    hdrs = ["TestUtils/CommonUtils.h"],
)

cc_library(
    name = "point-utils",
    srcs = ["TestUtils/PointUtils.cpp"],
    hdrs = ["TestUtils/PointUtils.h"],
    deps = [
        "common-utils",
        "//main:primitives",
    ],
)

cc_test(
    name = "testbacan",
    size = "small",
    srcs = ["Primitives/point_test.cpp"],
    deps = [
        ":point-utils",
        ":testing",
    ],
)
