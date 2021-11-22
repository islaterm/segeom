load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_library(
    name = "Utils",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.h"]),
)

cc_binary(
    name = "Segeom",
    srcs = ["Segeom.cpp"],
    deps = ["Utils"],
)
