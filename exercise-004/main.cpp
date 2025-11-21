#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"
// Ausgabe 3
#include "image.h"
// Aufgabe 5
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());

    // Aufgabe 3
    fmt::println("Breite:\t{}", image_width);
    fmt::println("Höhe:\t{}", image_height);
    fmt::println("Größe (Byte):\t{}", sizeof(image));
    fmt::println("Mach dich ab G'schissaner");

    // Aufgabe 4
    // Nicht lösbar?

    // Aufgabe 5
    // image ist const unsigned char*, Länge ist width * height * 3 (für RGB)
    cv::Mat img(image_height, image_width, CV_8UC3, (void *)image);
    // img kann jetzt direkt genutzt werden, z.B. Image anzeigen oder Parameter ausgeben
    fmt::println("OpenCV Bild-Parameter:");
    fmt::println("Breite: {}", img.cols);
    fmt::println("Höhe: {}", img.rows);
    fmt::println("Kanäle: {}", img.channels());

    // Aufgabe 6

    return 0; /* exit gracefully*/
}
