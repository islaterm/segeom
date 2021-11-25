load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_library(
    name = "utils",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.h"]),
)

cc_library(
    name = "primitives",
    srcs = [
        "Primitives/Point.cpp",
        "Primitives/PointND.cpp",
        "Primitives/Point2D.cpp"
    ],
    hdrs = [
        "Primitives/Point.h",
        "Primitives/PointND.h",
        "Primitives/Point2D.h"
    ],
    visibility = ["//test:__pkg__"],
    deps = ["utils"],
)

cc_binary(
    name = "Segeom",
    srcs = ["Segeom.cpp"],
    deps = ["utils"],
)
