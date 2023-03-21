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

    dst_path = os.path.join(sys.argv[2], "pp_for_impl.hpp")

    with open(dst_path, "w") as fout:
        fout.write(
            "#ifndef ERYTHRONELUMBO_MAIHUENIA_DETAIL_PREPROCESSOR_PP_FOR_IMPL"
            "_HPP\n"
            "#define ERYTHRONELUMBO_MAIHUENIA_DETAIL_PREPROCESSOR_PP_FOR_IMPL"
            "_HPP\n"
            "\n\n"
        )
        fout.write(
            "#define ERYTHRONELUMBO_MAIHUENIA_DETAIL_PP_FOR_IMPL_0(f,x,d)\n"
        )
        if num_instances >= 1:
            fout.write(
                "#define ERYTHRONELUMBO_MAIHUENIA_DETAIL_PP_FOR_IMPL_1(f,x,d)"
                " \\\n"
                "ERYTHRONELUMBO_MAIHUENIA_PP_DEFER(f)(0,x)\n"
            )
        for i in range(1, num_instances):
            fout.write(
                f"#define ERYTHRONELUMBO_MAIHUENIA_DETAIL_PP_FOR_IMPL_{i + 1}"
                "(f,x,d) \\\n"
                f"ERYTHRONELUMBO_MAIHUENIA_DETAIL_PP_FOR_IMPL_{i}(\\\n"
                "  f,x,ERYTHRONELUMBO_MAIHUENIA_PP_IDENTITY(d)\\\n"
                f")d()ERYTHRONELUMBO_MAIHUENIA_PP_DEFER(f)({i},x)\n"
            )
        fout.write(
            "\n#endif // ERYTHRONELUMBO_MAIHUENIA_DETAIL_PREPROCESSOR_PP_FOR_"
            "IMPL_HPP\n"
        )
