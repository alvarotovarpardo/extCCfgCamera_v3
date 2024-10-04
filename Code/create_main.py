import os

def createMainCpp():
    output_path = os.path.join(os.getcwd(),'C_Code')
    output_file = os.path.join(output_path, 'main.cpp')
    
    with open(output_file, 'w') as f:
        f.write("#include \"config_base.h\"\n")
        f.write("#include \"config_camera.h\"\n")
        f.write("\n")
        f.write("int main(){\n")
        f.write("    return 0;\n")
        f.write("}\n")

    
