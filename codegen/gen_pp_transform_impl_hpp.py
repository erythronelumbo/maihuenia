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

    dst_path = os.path.join(sys.argv[2], "pp_transform_impl.hpp")

    with open(dst_path, "w") as fout:
        fout.write(
            "#ifndef ERYTHRONELUMBO_MAIHUENIA_DETAIL_PREPROCESSOR_PP_TRANSFORM"
            "_IMPL_HPP\n"
            "#define ERYTHRONELUMBO_MAIHUENIA_DETAIL_PREPROCESSOR_PP_TRANSFORM"
            "_IMPL_HPP\n"
            "\n\n"
        )
        fout.write(
            "#define ERYTHRONELUMBO_MAIHUENIA_DETAIL_PP_TRANSFORM_IMPL_0("
            "f,d,s,x)\n"
        )
        if num_instances >= 1:
            fout.write(
                "#define ERYTHRONELUMBO_MAIHUENIA_DETAIL_PP_TRANSFORM_IMPL_1("
                "f,d,s,x) \\\n"
                "ERYTHRONELUMBO_MAIHUENIA_PP_DEFER(f)( \\\n"
                "  ERYTHRONELUMBO_MAIHUENIA_PP_UNPACK( \\\n"
                "    ERYTHRONELUMBO_MAIHUENIA_PP_VA_HEAD s \\\n"
                "  ), x \\\n"
                ")\n"
            )
        for i in range(1, num_instances):
            fout.write(
                "#define ERYTHRONELUMBO_MAIHUENIA_DETAIL_PP_TRANSFORM_IMPL_"
                f"{i + 1}(f,d,s,x) \\\n"
                "ERYTHRONELUMBO_MAIHUENIA_PP_DEFER(f)( \\\n"
                "  ERYTHRONELUMBO_MAIHUENIA_PP_UNPACK( \\\n"
                "    ERYTHRONELUMBO_MAIHUENIA_PP_VA_HEAD s \\\n"
                "  ), x \\\n"
                f")d()ERYTHRONELUMBO_MAIHUENIA_DETAIL_PP_TRANSFORM_IMPL_{i}"
                "( \\\n"
                "  f, ERYTHRONELUMBO_MAIHUENIA_PP_IDENTITY(d), \\\n"
                "  ERYTHRONELUMBO_MAIHUENIA_PP_UNPACK( \\\n"
                "    ERYTHRONELUMBO_MAIHUENIA_PP_VA_TAIL s \\\n"
                "  ), x \\\n"
                ")\n"
            )
        fout.write(
            "\n#endif // ERYTHRONELUMBO_MAIHUENIA_DETAIL_PREPROCESSOR_PP_"
            "TRANSFORM_IMPL_HPP\n"
        )
