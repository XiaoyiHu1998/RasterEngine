#ifndef IMPORTER_OBJ_HPP
#define IMPORTER_OBJ_HPP

#include "Importer.hpp"

enum class objKeys {
    // vertex data
    v, vt, vn, vp, cstype, deg, bmat, step,
    //elements, surface area
    p, l, t, curve, curve2, surf,
    //freeform curve/surface body statements
    parm, trim, hole, scrv, sp, end,
    // freeform surface connectivity
    con,
    //grouping
    g, s, m, o,
    // render attributes
    bevel, c_interp, d_interp, lod, usemtl, mtllib, shadow_obj, ctech, stech
};




class Importer_OBJ : public Importer{
private:
    bool mtlPresentForCurrentFile;
    std::string mtlFilePath;
    std::string materialName;
    std::set<std::string> keywords = {
        // vertex data
        "v", "vt", "vn", "vp", "cstype", "deg", "bmat", "step",
        //elements, surface area
        "p", "l", "t", "curve", "curve2", "surf",
        //freeform curve/surface body statements
        "parm", "trim", "hole", "scrv", "sp", "end",
        // freeform surface connectivity
        "con",
        //grouping
        "g", "s", "m", "o",
        // render attributes
        "bevel", "c_interp", "d_interp", "lod", "usemtl", "mtllib", "shadow_obj", "ctech", "stech"
    };

    void handleInputLine(const std::string& inputLine, std::vector<PreMesh>& preMeshes) override;
    bool legalKeyword(std::string& keyword);
public:
    Importer_OBJ(std::shared_ptr<Scene> scenePointer);
    Mesh import(const std::string& filepath) override;
};

#endif //IMPORTER_OBJ_HPP