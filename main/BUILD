load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_library(
    name = "utils",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.h"]),
)

cc_library(
    name = "primitives",
    hdrs = glob(["primitives/*.h"]),
    visibility = ["//test:__pkg__"],
    deps = ["utils"],
)

cc_binary(
    name = "Segeom",
    srcs = ["Segeom.cpp"],
    deps = ["utils"],
)
