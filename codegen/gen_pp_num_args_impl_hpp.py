# Copyright (c) 2023 Álvaro Ceballos
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

import sys, os


if __name__ == "__main__":
    num_cols = 10

    num_instances = int(sys.argv[1])

    if num_instances < 1:
        print("The number of instances must be 1 or higher.")
        exit()

    dst_path = os.path.join(sys.argv[2], "pp_num_args_impl.hpp")

    with open(dst_path, "w") as fout:
        rs = num_instances // num_cols
        cs = num_instances % num_cols
        is_cs_nzr = cs > 0
        fout.write(
            "#ifndef ERYTHRONELUMBO_MAIHUENIA_DETAIL_PREPROCESSOR_PP_NUM_ARGS"
            "_IMPL_HPP\n"
            "#define ERYTHRONELUMBO_MAIHUENIA_DETAIL_PREPROCESSOR_PP_NUM_ARGS"
            "_IMPL_HPP\n"
            "\n\n"
        )
        fout.write(
            "#define ERYTHRONELUMBO_MAIHUENIA_DETAIL_PP_NUM_ARGS_IMPL_1( \\\n"
        )
        iiy = 0
        for iy in range(rs):
            fout.write(
                "  " + ", ".join(
                    [f"x{(iiy + ix):03}" for ix in range(num_cols)]
                ) + ", \\\n"
            )
            iiy += num_cols
        if is_cs_nzr:
            fout.write(
                "  " + ", ".join(
                    [f"x{(iiy + ix):03}" for ix in range(cs)]
                ) + ", \\\n"
            )
        fout.write(
            "  cnt, ... \\\n"
            ") cnt\n"
        )
        fout.write(
            "#define ERYTHRONELUMBO_MAIHUENIA_DETAIL_PP_NUM_ARGS_IMPL(...) \\\n"
            "ERYTHRONELUMBO_MAIHUENIA_DETAIL_PP_NUM_ARGS_IMPL_1( \\\n"
            f"  __VA_ARGS__, {num_instances}, \\\n"
        )
        iiy = 0
        for iy in range(rs):
            iiy_ = num_instances - 1 - iiy
            fout.write(
                "  " + ", ".join(
                    [f"{(iiy_ - ix):3}" for ix in range(num_cols)]
                )
            )
            if iy < (rs - 1) or is_cs_nzr:
                fout.write(",")
            fout.write(" \\\n")
            iiy += num_cols
        if is_cs_nzr:
            fout.write(
                "  " + ", ".join(
                    [f"{(num_instances - 1 - iiy - ix):3}" for ix in range(cs)]
                ) + "\\\n"
            )
        fout.write(
            ")\n"
            "\n"
            "#endif // ERYTHRONELUMBO_MAIHUENIA_DETAIL_PREPROCESSOR_PP_NUM_"
            "ARGS_IMPL_HPP\n"
        )
