#ifndef MULTIGEN_PROCESSORS_SDK_PROCESSOR_HPP
#define MULTIGEN_PROCESSORS_SDK_PROCESSOR_HPP

#include "base_processor.hpp"

namespace multigen {
    class sdk_processor : public base_processor {
    public:
        bool initialize(const std::vector<std::shared_ptr<metadata_container>>& metadata_containers) override {
            metadata_containers_ = metadata_containers;
            return resolve_dependencies();
        }

        bool resolve_dependencies() {
            if (metadata_containers_.empty())
                return false;

            // TODO: Kahn's algorithm

            return true;
        }

        bool serialize(const std::shared_ptr<base_serializer>& serializer) override {
            for (const auto& container : metadata_containers_) {
                serialized_file serialized_file;
                auto& writer = serialized_file.content;

                writer << "// Generated by MultiGen https://github.com/ooodummy/multigen\n";
                if (!serializer->serialize(writer, container))
                    return false;

                auto folder_parts = container->type->name_space;
                std::ranges::replace(folder_parts, '.', '/');

                serialized_file.container = container;
                serialized_file.directory = folder_parts;
                serialized_file.name = container->type->type_name + ".hpp";

                //serialized_files_.push_back(serialized_file);
            }

            return true;
        }

        bool write(const std::filesystem::path output_directory) override {
            std::stringstream writer;

            constexpr auto header_guard = "SDK_AUTO_SDK_HPP";
            writer << "#ifndef " << header_guard << "\n";
            writer << "#define " << header_guard << "\n\n";

            const auto root_directory = output_directory / "sdk";
            if (!exists(root_directory) && !create_directories(root_directory))
                return false;

            for (const auto& serialized_file : serialized_files_) {
                const auto directory = root_directory / serialized_file.directory;
                if (!exists(directory) && !create_directories(directory))
                    return false;

                std::ofstream file(directory / serialized_file.name);
                if (!file.is_open())
                    return false;

                file << serialized_file.content.str();

                if (file.fail())
                    return false;
            }

            writer << "#endif\n";

            std::ofstream main_file(output_directory / "auto_sdk.hpp");
            if (!main_file.is_open())
                return false;

            main_file << writer.str();

            if (main_file.fail())
                return false;

            return true;
        }

    private:
        std::vector<std::shared_ptr<metadata_container>> metadata_containers_;

        struct serialized_file {
            std::shared_ptr<metadata_container> container;
            std::filesystem::path directory;
            std::string name;
            std::stringstream content;
        };

        std::vector<serialized_file> serialized_files_;
    };
}

#endif