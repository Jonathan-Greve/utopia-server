set_project("Utopia Server")
set_version("0.0.1")

set_languages("c++latest")

add_rules("mode.debug", "mode.release")


-- Setup for debug symbols and optimization
if is_mode("debug") then
    set_symbols("debug")
    set_optimize("none")
else
    set_symbols("hidden")
    set_optimize("fastest")
    set_strip("all")
end

-- Function to add platform-specific flags
function add_platform_specific_flags()
    if is_plat("windows") then
        add_cxxflags("/EHsc")
        add_cxxflags("/Zc:__cplusplus")
        add_cxflags("/bigobj")
        
        -- Disable warnings
        add_cxflags("/wd4068") -- unknown pragma
        add_cxflags("/wd5045") -- Compiler will insert Spectre mitigation for memory load if /Qspectre switch specified
        add_cxflags("/wd4514") -- unreferenced inline function has been removed
        add_cxflags("/wd4866") -- compiler may not enforce left-to-right evaluation order
        add_cxflags("/wd4710") -- function not inlined
        add_cxflags("/wd4711") -- selected for automatic inline expansion
        add_cxflags("/wd4820") -- padding added after data member
        add_cxflags("/wd4365") -- 'initializing': conversion from 'type1' to 'type2', signed/unsigned mismatch
        add_cxflags("/wd5246") -- The initialization of a subobject should be wrapped in braces
        add_cxflags("/wd5267") -- definition of implicit copy constructor for 'utopia::common::PacketReader' is deprecated because it has a user-provided destructor
    else
        -- Add flags for e.g. linux here

        -- Disable warningsenginebgf
        add_cxflags("-Wno-c++98-compat")
        add_cxflags("-Wno-c++98-compat-pedantic")
        add_cxflags("-Wno-padded")
        add_cxflags("-Wno-unknown-pragmas")
        add_cxflags("-Wno-used-but-marked-unused")
        add_cxflags("-Wno-switch-default")
        add_cxflags("-Wno-missing-field-initializers")
    end
end

function add_common_requires()
    add_requires("spdlog", "glm", "argparse", "entt", "asio", "mbedtls ~2.28.3", "magic_enum",
                 "boost_sml", "concurrentqueue", "utfcpp", "ftxui", "boost", "scnlib",
                 "pugixml")
end

function add_common_packages()
    add_packages("spdlog", "glm", "argparse", "entt", "asio", "mbedtls", "magic_enum", 
                 "boost_sml", "concurrentqueue", "utfcpp", "ftxui", "boost", "scnlib",
                 "pugixml")
end

add_common_requires()

target("utopia-portal_server")
    set_kind("binary")
    set_pcxxheader("include/utopia/utopia_pch.hpp")
    set_warnings("all")
    add_common_packages()
    add_files("src/portal_server**.cpp")
    add_files("src/common**.cpp")
    add_headerfiles("include/**.hpp")
    add_includedirs("include/")
    add_platform_specific_flags()

    after_build(function (target)
            local destDir = path.join("$(buildir)", "$(plat)", "$(arch)", "$(mode)")
            print("Copying data to " .. destDir)
            os.cp("$(projectdir)/data", destDir)
        end)
target_end()