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

    dst_path = os.path.join(sys.argv[2], "pp_at_impl.hpp")

    with open(dst_path, "w") as fout:
        fout.write(
            "#ifndef ERYTHRONELUMBO_MAIHUENIA_DETAIL_PREPROCESSOR_PP_AT_IMPL"
            "_HPP\n"
            "#define ERYTHRONELUMBO_MAIHUENIA_DETAIL_PREPROCESSOR_PP_AT_IMPL"
            "_HPP\n"
            "\n\n"
        )
        for i in range(num_instances):
            ii = i + 1
            rs = ii // num_cols
            cs = ii % num_cols
            fout.write(
                f"#define ERYTHRONELUMBO_MAIHUENIA_DETAIL_PP_AT_IMPL_{i}( \\\n"
            )
            iiy = 0
            for iy in range(rs):
                fout.write(
                    "  " + ", ".join(
                        [f"x{(iiy + ix):03}" for ix in range(num_cols)]
                    ) + ", \\\n"
                )
                iiy += num_cols
            if cs > 0:
                fout.write(
                    "  " + ", ".join(
                        [f"x{(iiy + ix):03}" for ix in range(cs)]
                    ) + ", \\\n"
                )
                iiy += num_cols
            fout.write(
                "  ... \\\n"
                ") \\\n"
            )
            fout.write(f"x{i:03}\n")
        fout.write(
            "\n#endif // ERYTHRONELUMBO_MAIHUENIA_DETAIL_PREPROCESSOR_PP_AT_"
            "IMPL_HPP\n"
        )
