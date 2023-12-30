# Sample static library
add_library(samplelib STATIC)

set_target_properties(samplelib PROPERTIES OUTPUT_NAME "sample")

target_sources(
    samplelib
    PRIVATE
        "library.cpp"
        "library.h"
 "labels/Label.h" "labels/SimpleLabel.h" "labels/SimpleLabel.cpp" "labels/RichLabel.h" "labels/RichLabel.cpp" "labels/TransformText.h" "labels/LabelDecorator.h" "labels/LabelDecorator.cpp" "labels/RandomLabelDecorator.h" "labels/RandomLabelDecorator.cpp" "labels/CapitalizeText.h" "labels/CapitalizeText.cpp" "labels/Replace.h" "labels/Replace.cpp" "labels/CompositeDecorator.h" "labels/CompositeDecorator.cpp" "labels/CompositeTransform.h" "labels/CompositeTransform.cpp" "labels/CustomLabel.h" "labels/CustomLabel.cpp")


# Executable target for the application
add_executable(application)

set_target_properties(application PROPERTIES OUTPUT_NAME "calc")

target_link_libraries(
    application
    PRIVATE
        samplelib
)

target_sources(
    application
    PRIVATE
        "application.cpp"
 "labels/Label.h" "labels/SimpleLabel.h" "labels/SimpleLabel.cpp" "labels/RichLabel.h" "labels/RichLabel.cpp" "labels/TransformText.h" "labels/LabelDecorator.h" "labels/LabelDecorator.cpp" "labels/RandomLabelDecorator.h" "labels/RandomLabelDecorator.cpp" "labels/CapitalizeText.h" "labels/CapitalizeText.cpp" "labels/Replace.h" "labels/Replace.cpp" "labels/CompositeDecorator.h" "labels/CompositeDecorator.cpp" "labels/CompositeTransform.h" "labels/CompositeTransform.cpp" "labels/CustomLabel.h" "labels/CustomLabel.cpp")