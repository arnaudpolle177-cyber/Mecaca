#pragma once

#include <filesystem>
#include <string>

namespace meccha
{
    inline constexpr wchar_t DefaultGameProcessName[] = L"PenguinHotel-Win64-Shipping.exe";

    struct PaintTuning
    {
        double brush_radius{0.01};
        double brush_spacing{0.18};
        double server_brush_spacing{0.08};
        int server_batch_limit{50};
        int server_batch_delay_ms{300};
        // Humanization options
        double jitter{0.0};               // UV position jitter [0..1] (0=off, 1=max ~0.5*radius)
        double pressure_randomize{0.0};   // Radius variance [0..1] (0=off, 1=±40% radius)
        double color_humanize{0.0};       // Per-stroke color noise [0..1] (0=off, 1=±3% per channel)
        double spacing_randomize{0.0};    // Spacing variance [0..1] (0=off, 1=±50% spacing)
        bool stroke_smoothing{false};     // Bézier smoothing between adjacent strokes
    };

    struct AppSettings
    {
        int layout_version{7};
        float panel_x{-1.0f};
        float panel_y{-1.0f};
        float panel_width{1280.0f};
        float panel_height{860.0f};
        int log_retention_days{14};
        std::wstring game_process_name{DefaultGameProcessName};
        bool always_on_top{true};
        float opacity{1.0f};
        std::string paint_hotkey{"F10"};
        PaintTuning tuning{};
        bool show_info{true};
        bool show_warning{true};
        bool show_error{true};
    };

    auto default_app_dir() -> std::filesystem::path;
    auto config_path() -> std::filesystem::path;
    auto default_tuning() -> PaintTuning;
    void clamp_settings(AppSettings& settings);
    auto load_settings() -> AppSettings;
    auto save_settings(const AppSettings& settings) -> bool;
}
