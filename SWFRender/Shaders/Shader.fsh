//
//  Shader.fsh
//  SWFRender
//
//  Created by Sergey Fedortsov on 27.1.14.
//  Copyright (c) 2014 Sergey Fedortsov. All rights reserved.
//

varying lowp vec4 colorVarying;

void main()
{
    gl_FragColor = colorVarying;
}
