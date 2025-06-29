package com.hyki.tool;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.List;

public class GenerateAst {
    public static void main(String[] args) throws IOException {
        if (args.length != 1) {
            System.err.println("Usage: generate_ast <output directory>");
            System.exit(64);
        }
        String outputDir = args[0];
        defineAst(outputDir, "Expr", Arrays.asList(
                    "Binary : Expr left, Token operator, Expr right",
                    "Grouping : Expr expression",
                    "Literal : Object value",
                    "Unary : Token operator, Expr right"
                    ));
    }

    private static void defineAst(String outputDir, String baseName, List<String> types) throws IOException {
        String path = outputDir + "/" + baseName + ".java";
        PrintWriter writer = new PrintWriter(path, "UTF-8");

        // Write the package declaration and imports
        writer.println("package com.hyki.hi;");
        writer.println();
        writer.println("import java.util.List;");
        writer.println();

        // Write abstract class declaration
        writer.println("abstract class " + baseName + " {");

        for (String type : types) {
            String className = type.split(":")[0].trim();
            String fields = type.split(":")[1].trim();
            defineType(writer, baseName, className, fields);
        }

        // End of abstract class
        writer.println("}");
        writer.close();
    }

    private static void defineType(PrintWriter writer, String baseName, String className, String fields) {
        // Write static class declaration
        writer.println("    static class " + className + " extends " + baseName + " {");

        // constructor
        writer.println("    " + className + "(" + fields + ") {");

        String[] fieldList = fields.split(", ");
        for (String field : fieldList) {
            String name = field.split(" ")[1];
            writer.println("            this." + name + " = " + name + ";");
        }

        writer.println("        }");

        // fields
        writer.println();
        for (String field : fieldList) {
            writer.println("        final " + field + ";");
        }

        // End of static class
        writer.println("    }");
    }
}
