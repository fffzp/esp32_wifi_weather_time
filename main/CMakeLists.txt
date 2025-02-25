file(GLOB_RECURSE srcs *.c
                    ui/custom/*.c
                    ui/generated/*.c
                    ui/generated/guider_customer_fonts/*.c
                    ui/generated/guider_fonts/*.c
                    ui/generated/images/*.c
                    app/*.c
                    esp32_s3_szp.c
                    main.c
                    )
set(include_dirs 
    . 
    ui/custom 
    ui/generated 
    ui/generated/guider_customer_fonts
    ui/generated/guider_fonts
    ui/generated/images
    app
)
    
idf_component_register(
    SRCS ${srcs}
    INCLUDE_DIRS ${include_dirs}
    EMBED_FILES "canon.pcm"
)         
