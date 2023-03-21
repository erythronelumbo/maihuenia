# Copyright (c) 2023 Álvaro Ceballos
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

import sys, os

TABULATION = "  "


def nest_binop_many_r(fout, num : int, extra_tabs = 0):
    ii = 0
    for i in range(num):
        ii = i + extra_tabs
        fout.write(TABULATION * ii)
        if i > 0:
            fout.write("typename ")
        fout.write("BinOp<\n")
        fout.write(TABULATION * (ii + 1))
        fout.write(f"X{i:02},\n")
    if num >= 1:
        fout.write(TABULATION * (ii + 1))
        fout.write(f"typename bin_op_many_impl<\n")
        fout.write(TABULATION * (ii + 2))
        fout.write("BinOp, IsRightAssoc, Xs...\n")
        fout.write(TABULATION * (ii + 1))
        fout.write(">::type\n")
    i_max = num - 1
    for i in range(num):
        ii_ = (num - 1 - i) + extra_tabs
        tb1 = TABULATION * ii_
        fout.write(tb1 + ">")
        if i < i_max:
            fout.write("::type")
        fout.write("\n")

def nest_binop_many_r1(fout, num : int, extra_tabs = 0):
    ii = 0
    for i in range(num - 1):
        ii = i + extra_tabs
        fout.write(TABULATION * ii)
        if i > 0:
            fout.write("typename ")
        fout.write("BinOp<\n")
        fout.write(TABULATION * (ii + 1))
        fout.write(f"X{i:02},\n")
        if i == (num - 2):
            fout.write(TABULATION * (ii + 1))
            fout.write(f"X{(i + 1):02}\n")
    i_max = num - 1
    for i in range(num - 1):
        ii_ = (num - 2 - i) + extra_tabs
        tb1 = TABULATION * ii_
        fout.write(tb1 + ">")
        if i < (i_max - 1):
            fout.write("::type")
        fout.write("\n")

def nest_binop_many_l(fout, num : int, extra_tabs = 0, final_comma = False):
    i = 0
    for i in range(num - 1):
        ii = i + extra_tabs
        fout.write(TABULATION * ii)
        if i > 0 or final_comma:
            fout.write("typename ")
        fout.write("BinOp<\n")
    i_max = num - 2
    for i in range(num - 1):
        ii = (num - 2 - i) + extra_tabs
        tb1 = TABULATION * ii
        fout.write(tb1 + TABULATION)
        if i == 0:
            fout.write(f"X{i:02}, X{(i + 1):02}\n")
        else:
            fout.write(f"X{(i + 1):02}\n")
        fout.write(tb1 + ">")
        if i < i_max or final_comma:
            fout.write("::type,")
        fout.write("\n")


if __name__ == "__main__":
    cols1 = 4
    cols2 = 10

    unroll_factor = int(sys.argv[1])

    if unroll_factor < 1:
        print("The unroll factor must be 1 or higher.")
        exit()

    dst_path = os.path.join(sys.argv[2], "bin_op_many_impl.hpp")

    rows1 = unroll_factor // cols1
    rows2 = unroll_factor // cols2

    with open(dst_path, "w") as fout:
        fout.write(
            "/**\n"
            " * @file bin_op_many_impl.hpp\n"
            " *\n"
            " * Automatically generated, unrolled helper for some binary "
            "metafunctions.\n"
            " */\n"
            "\n"
            "#ifndef ERYTHRONELUMBO_MAIHUENIA_DETAIL_BIN_OP_MANY_IMPL_HPP\n"
            "#define ERYTHRONELUMBO_MAIHUENIA_DETAIL_BIN_OP_MANY_IMPL_HPP\n"
            "\n"
            "\n"
            "#include <erythronelumbo/maihuenia/version.hpp>\n"
            "#include <erythronelumbo/maihuenia/config.hpp>\n"
            "\n"
            "\n"
            "namespace erythronelumbo { namespace maihuenia\n"
            "{\n"
            "\n"
            "namespace detail\n"
            "{\n"
            "\n"
            "template <\n"
            "  template <typename...> class, bool,\n"
            "  typename, typename, typename...\n"
            ">\n"
            "struct bin_op_many_impl;\n"
            "\n"
            "template < \n"
            "  template <typename...> class BinOp, bool IsRightAssoc,\n"
            "  typename X1, typename X2\n"
            ">\n"
            "struct bin_op_many_impl<BinOp, IsRightAssoc, X1, X2> : BinOp<X1,"
            " X2>"
            " {};\n"
            "\n"
            "template <\n"
            "  template <typename...> class BinOp, bool IsRightAssoc,\n"
        )
        iiy = 0
        for iy in range(rows1):
            fout.write(
                TABULATION +
                ", ".join([
                    f"typename X{(iiy + ix):02}" for ix in range(cols1)
                ]) +
                ",\n"
            )
            iiy += cols1
        fout.write(
            "  typename... Xs\n"
            ">\n"
            "struct bin_op_many_impl<\n"
            "  BinOp, IsRightAssoc,\n"
        )
        iiy = 0
        for iy in range(rows2):
            fout.write(
                TABULATION +
                ", ".join([f"X{(iiy + ix):02}" for ix in range(cols2)]) +
                ",\n"
            )
            iiy += cols2
        fout.write(
            "  Xs...\n"
            "> :\n"
        )
        nest_binop_many_r(fout, unroll_factor, extra_tabs=1)
        fout.write(
            "{};\n\n"
        )
        for i in range(unroll_factor, 2, -1):
            rows1_ = i // cols1
            rows2_ = i // cols2
            rmcs1_ = i % cols1
            rmcs2_ = i % cols2
            fout.write(
                "template <\n"
                "  template <typename...> class BinOp, bool"
                " IsRightAssoc,\n"
            )
            iiy = 0
            for iy in range(rows1_):
                fout.write(
                    TABULATION +
                    ", ".join([
                        f"typename X{(iiy + ix):02}" for ix in range(cols1)
                    ])
                )
                if iy < (rows1_ - 1) or rmcs1_ > 0:
                    fout.write(",")
                fout.write("\n")
                iiy += cols1
            if rmcs1_ > 0:
                fout.write(
                    TABULATION +
                    ", ".join([
                        f"typename X{(iiy + ix):02}" for ix in range(rmcs1_)
                    ]) +
                    "\n"
                )
            fout.write(
                ">\n"
                "struct bin_op_many_impl<\n"
                "  BinOp, IsRightAssoc,\n"
            )
            iiy = 0
            for iy in range(rows2_):
                fout.write(
                    TABULATION +
                    ", ".join([f"X{(iiy + ix):02}" for ix in range(cols2)])
                )
                if iy < (rows2_ - 1) or rmcs2_ > 0:
                    fout.write(",")
                fout.write("\n")
                iiy += cols2
            if rmcs2_ > 0:
                fout.write(
                    TABULATION +
                    ", ".join([f"X{(iiy + ix):02}" for ix in range(rmcs2_)]) +
                    "\n"
                )
            fout.write("> :\n")
            nest_binop_many_r1(fout, i, extra_tabs=1)
            fout.write("{};\n\n")

        # Left-associative operations

        fout.write(
            "template <\n"
            "  template <typename...> class BinOp,\n"
        )
        iiy = 0
        for iy in range(rows1):
            fout.write(
                TABULATION +
                ", ".join([
                    f"typename X{(iiy + ix):02}" for ix in range(cols1)
                ]) +
                ",\n"
            )
            iiy += cols1
        fout.write(
            "  typename... Xs\n"
            ">\n"
            "struct bin_op_many_impl<\n"
            "  BinOp, false,\n"
        )
        iiy = 0
        for iy in range(rows2):
            fout.write(
                TABULATION +
                ", ".join([f"X{(iiy + ix):02}" for ix in range(cols2)]) +
                ",\n"
            )
            iiy += cols2
        fout.write(
            "  Xs...\n"
            "> :\n"
            "  bin_op_many_impl<\n"
            "    BinOp, false,\n"
        )
        nest_binop_many_l(fout, unroll_factor, final_comma=True, extra_tabs=2)
        fout.write(
            "    Xs...\n"
            "  >\n"
            "{};\n\n"
        )
        for i in range(unroll_factor, 2, -1):
            rows1_ = i // cols1
            rows2_ = i // cols2
            rmcs1_ = i % cols1
            rmcs2_ = i % cols2
            fout.write(
                "template <\n"
                "  template <typename...> class BinOp,\n"
            )
            iiy = 0
            for iy in range(rows1_):
                fout.write(
                    TABULATION +
                    ", ".join([
                        f"typename X{(iiy + ix):02}" for ix in range(cols1)
                    ])
                )
                if iy < (rows1_ - 1) or rmcs1_ > 0:
                    fout.write(",")
                fout.write("\n")
                iiy += cols1
            if rmcs1_ > 0:
                fout.write(
                    TABULATION +
                    ", ".join([
                        f"typename X{(iiy + ix):02}" for ix in range(rmcs1_)
                    ]) +
                    "\n"
                )
            fout.write(
                ">\n"
                "struct bin_op_many_impl<\n"
                "  BinOp, false,\n"
            )
            iiy = 0
            for iy in range(rows2_):
                fout.write(
                    TABULATION +
                    ", ".join([f"X{(iiy + ix):02}" for ix in range(cols2)])
                )
                if iy < (rows2_ - 1) or rmcs2_ > 0:
                    fout.write(",")
                fout.write("\n")
                iiy += cols2
            if rmcs2_ > 0:
                fout.write(
                    TABULATION +
                    ", ".join([f"X{(iiy + ix):02}" for ix in range(rmcs2_)]) +
                    "\n"
                )
            fout.write("> :\n")
            nest_binop_many_l(fout, i, extra_tabs=1, final_comma=False)
            fout.write("{};\n\n")

        fout.write(
            "} // namespace detail\n"
            "\n"
            "}} // namespace erythronelumbo::maihuenia\n"
            "\n\n"
            "#endif // ERYTHRONELUMBO_MAIHUENIA_DETAIL_BIN_OP_MANY_IMPL_HPP\n"
        )
    pass
