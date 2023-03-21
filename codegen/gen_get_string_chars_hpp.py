# Copyright (c) 2023 Álvaro Ceballos
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

import sys, os


if __name__ == "__main__":
    max_lenght = int(sys.argv[1])
    unroll_factor = int(sys.argv[2])

    if max_lenght < 1:
        print("The maximum length for string literals must be 1 or higher.")
        exit()

    if unroll_factor < 1:
        print("The unroll factor must be 1 or higher.")
        exit()

    args2a = [f"char C{i:02}_" for i in range(unroll_factor)]

    dst_path = os.path.join(sys.argv[3], "get_string_chars.hpp")

    with open(dst_path, "w") as fout:
        fout.write(
            "#ifndef ERYTHRONELUMBO_MAIHUENIA_DETAIL_GET_STRING_CHARS_HPP\n"
            "#define ERYTHRONELUMBO_MAIHUENIA_DETAIL_GET_STRING_CHARS_HPP\n"
            "\n\n"
            "#include <erythronelumbo/maihuenia/detail/preprocessor.hpp>\n"
            "\n\n"
            "#define ERYTHRONELUMBO_MAIHUENIA_STRING_DETAIL_MAX_ALLOWED_LENGTH"
            f" {max_lenght}\n"
            "\n\n"
            "namespace erythronelumbo { namespace maihuenia { namespace "
            "detail\n"
            "{\n"
            "\n"
        )
        fout.write("template <typename> struct str_add_lit_chs_impl;\n\n")
        fout.write(
            "template <char... Cs>\n"
            "struct str_add_lit_chs_impl<string<Cs...>>\n"
            "{\n"
        )
        fout.write(
            "  template <\n"
            "    typename X,\n"
        )
        ncols = 4
        nrows = unroll_factor // ncols
        nrmas = unroll_factor % ncols
        ii = 0
        for i in range(nrows):
            fout.write("    ")
            for j in range(ncols):
                if j > 0:
                    fout.write(", ")
                fout.write(args2a[ii + j])
                fout.write(" = '\\0'")
            if i < (nrows - 1) or nrmas > 0:
                fout.write(",")
            fout.write("\n")
            ii += ncols
        if nrmas > 0:
            fout.write("    ")
            for j in range(nrmas):
                if j > 0:
                    fout.write(", ")
                fout.write(args2a[ii + j])
                fout.write(" = '\\0'")
            fout.write("\n")
        fout.write(
            "  >\n"
            "  struct res_ :\n"
            "    string<\n"
            "      Cs...,\n"
        )
        ncols = 8
        nrows = unroll_factor // ncols
        nrmas = unroll_factor % ncols
        ii = 0
        for i in range(nrows):
            fout.write("      ")
            for j in range(ncols):
                if j > 0:
                    fout.write(", ")
                fout.write(f"C{(ii + j):02}_")
            if i < (nrows - 1) or nrmas > 0:
                fout.write(",")
            fout.write("\n")
            ii += ncols
        if nrmas > 0:
            fout.write("      ")
            for j in range(nrmas):
                if j > 0:
                    fout.write(", ")
                fout.write(f"C{(ii + j):02}_")
            fout.write("\n")
        fout.write(
            "    >\n"
            "  {};\n"
        )

        args3 = [f"C{i:02}_" for i in range(unroll_factor)]

        for j in range(unroll_factor - 1, -1, -1):
            args3[j] = "'\\0'"
            fout.write("\n")
            fout.write("  template <\n")
            fout.write("    typename X")
            if j > 0:
                fout.write(",")
            fout.write("\n")
            ncols = 4
            nrows = j // ncols
            nrmas = j % ncols
            ii = 0
            for i in range(nrows):
                fout.write("    ")
                for k in range(ncols):
                    if k > 0:
                        fout.write(", ")
                    fout.write(args2a[ii + k])
                if i < (nrows - 1) or nrmas > 0:
                    fout.write(",")
                fout.write("\n")
                ii += ncols
            if nrmas > 0:
                fout.write("    ")
                for k in range(nrmas):
                    if k > 0:
                        fout.write(", ")
                    fout.write(args2a[ii + k])
                fout.write("\n")
            fout.write("  >\n")
            fout.write("  struct res_<\n")
            fout.write("    X,\n")
            ncols = 8
            nrows = unroll_factor // ncols
            nrmas = unroll_factor % ncols
            ii = 0
            for i in range(nrows):
                fout.write("    ")
                for k in range(ncols):
                    if k > 0:
                        fout.write(", ")
                    fout.write(args3[ii + k])
                if i < (nrows - 1) or nrmas > 0:
                    fout.write(",")
                fout.write("\n")
                ii += ncols
            if nrmas > 0:
                fout.write("    ")
                for k in range(nrmas):
                    if k > 0:
                        fout.write(", ")
                    fout.write(args3[ii + k])
                fout.write("\n")
            fout.write("  > :\n")
            fout.write("    string<\n")
            fout.write("      Cs...")
            if j > 0:
                fout.write(",")
            fout.write("\n")
            ncols = 8
            nrows = j // ncols
            nrmas = j % ncols
            ii = 0
            for i in range(nrows):
                fout.write("      ")
                for k in range(ncols):
                    if k > 0:
                        fout.write(", ")
                    fout.write(args3[ii + k])
                if i < (nrows - 1) or nrmas > 0:
                    fout.write(",")
                fout.write("\n")
                ii += ncols
            if nrmas > 0:
                fout.write("      ")
                for k in range(nrmas):
                    if k > 0:
                        fout.write(", ")
                    fout.write(args3[ii + k])
                fout.write("\n")
            fout.write("    >\n")
            fout.write("  {};\n")

        fout.write(
            "};\n"
            "\n"
            "template <typename Str, char... Cs>\n"
            "using str_add_lit_chs = typename str_add_lit_chs_impl<Str>"
            "::template res_<\n  void, Cs...\n>::type;\n"
            "\n"
            "}}} // namespace erythronelumbo::maihuenia::detail\n"
            "\n\n"
            "#define ERYTHRONELUMBO_MAIHUENIA_DETAIL_GSC_IMPL(ncs) \\\n"
            "ERYTHRONELUMBO_MAIHUENIA_PP_CONCAT_( \\\n"
            "  ERYTHRONELUMBO_MAIHUENIA_DETAIL_GSC_IMPL_, ncs \\\n"
            ")\n"
            "\n\n"
        )

        # Macros

        for i in range(1, unroll_factor + 1):
            fout.write(
                f"#define ERYTHRONELUMBO_MAIHUENIA_DETAIL_GSC_IMPL_UR_{i}" \
                "(s,ou) \\\n"
            )
            for j in range(i):
                fout.write(
                    "::erythronelumbo::maihuenia::detail::cstr_gch_" \
                    f"(s,ou+{j})"
                )
                if j < (i - 1):
                    fout.write(", \\")
                fout.write("\n")
            fout.write("\n")

        # Macros

        fout.write(
            "#define ERYTHRONELUMBO_MAIHUENIA_DETAIL_GSC_IMPL_0"
            "(str_acc,s) \\\n"
            "::erythronelumbo::maihuenia::string<>\n"
        )

        urd = max_lenght // unroll_factor
        urm = max_lenght % unroll_factor

        ii = 1
        pr = 0

        for i in range(1, urd + 1):
            fout.write("\n")
            for j in range(unroll_factor):
                fout.write(
                    "#define ERYTHRONELUMBO_MAIHUENIA_DETAIL_" \
                    f"GSC_IMPL_{ii}" \
                    "(str_acc,s) \\\n" \
                    "::erythronelumbo::maihuenia::detail::str_add_lit_chs< \\\n"
                )
                fout.write(
                    "  ERYTHRONELUMBO_MAIHUENIA_DETAIL_" \
                    f"GSC_IMPL_{pr}(str_acc,s), \\\n"
                )
                fout.write(
                    "  ERYTHRONELUMBO_MAIHUENIA_DETAIL_GSC_IMPL_UR_" \
                    f"{j + 1}(s,{pr}) \\\n"
                )
                fout.write(
                    ">\n"
                )
                ii += 1
            pr += unroll_factor
        if urm > 0:
            for j in range(urm):
                fout.write(
                    "#define ERYTHRONELUMBO_MAIHUENIA_DETAIL_" \
                    f"GSC_IMPL_{ii}" \
                    "(str_acc,s) \\\n" \
                    "::erythronelumbo::maihuenia::detail::str_add_lit_chs< \\\n"
                )
                fout.write(
                    "  ERYTHRONELUMBO_MAIHUENIA_DETAIL_" \
                    f"GSC_IMPL_{pr}(str_acc,s), \\\n"
                )
                fout.write(
                    "  ERYTHRONELUMBO_MAIHUENIA_DETAIL_GSC_IMPL_UR_" \
                    f"{j + 1}(s,{pr}) \\\n"
                )
                fout.write(
                    ">\n"
                )
                ii += 1
        fout.write(
            "\n\n"
            "#endif // ERYTHRONELUMBO_MAIHUENIA_DETAIL_GET_STRING_CHARS_HPP\n"
        )
