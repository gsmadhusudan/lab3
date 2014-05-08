package hwacha

import Chisel._

object HwachaInstructions
{
/* Automatically generated by parse-opcodes */
  def VSETCFG            = Bits("b?????????????????010000000001011")
  def VSETVL             = Bits("b000000000000?????110?????0001011")
  def VGETCFG            = Bits("b00000000000000000100?????0001011")
  def VGETVL             = Bits("b00000010000000000100?????0001011")
  def VMVV               = Bits("b000000100000?????000?????0101011")
  def VMSV               = Bits("b000000100000?????010?????0101011")
  def VFMVV              = Bits("b000100000000?????000?????0101011")
  def VFMSV_S            = Bits("b000100000000?????010?????0101011")
  def VFMSV_D            = Bits("b000100100000?????010?????0101011")
  def VF                 = Bits("b???????00001?????010?????0101011")
  def VXCPTCAUSE         = Bits("b00000000000000000100?????0101011")
  def VXCPTAUX           = Bits("b00000010000000000100?????0101011")
  def VXCPTSAVE          = Bits("b000000000000?????011000000101011")
  def VXCPTRESTORE       = Bits("b000000100000?????011000000101011")
  def VXCPTKILL          = Bits("b00000100000000000011000000101011")
  def VXCPTEVAC          = Bits("b000001100000?????011000000101011")
  def VXCPTHOLD          = Bits("b00001000000000000011000000101011")
  def VENQCMD            = Bits("b0000101??????????011000000101011")
  def VENQIMM1           = Bits("b0000110??????????011000000101011")
  def VENQIMM2           = Bits("b0000111??????????011000000101011")
  def VENQCNT            = Bits("b0001000??????????011000000101011")
  def VLSEGD             = Bits("b???001100000?????010?????1011011")
  def VLSEGW             = Bits("b???001000000?????010?????1011011")
  def VLSEGWU            = Bits("b???011000000?????010?????1011011")
  def VLSEGH             = Bits("b???000100000?????010?????1011011")
  def VLSEGHU            = Bits("b???010100000?????010?????1011011")
  def VLSEGB             = Bits("b???000000000?????010?????1011011")
  def VLSEGBU            = Bits("b???010000000?????010?????1011011")
  def VFLSEGD            = Bits("b???101100000?????010?????1011011")
  def VFLSEGW            = Bits("b???101000000?????010?????1011011")
  def VLSEGSTD           = Bits("b???0011??????????011?????1011011")
  def VLSEGSTW           = Bits("b???0010??????????011?????1011011")
  def VLSEGSTWU          = Bits("b???0110??????????011?????1011011")
  def VLSEGSTH           = Bits("b???0001??????????011?????1011011")
  def VLSEGSTHU          = Bits("b???0101??????????011?????1011011")
  def VLSEGSTB           = Bits("b???0000??????????011?????1011011")
  def VLSEGSTBU          = Bits("b???0100??????????011?????1011011")
  def VFLSEGSTD          = Bits("b???1011??????????011?????1011011")
  def VFLSEGSTW          = Bits("b???1010??????????011?????1011011")
  def VSSEGD             = Bits("b???001100000?????010?????1111011")
  def VSSEGW             = Bits("b???001000000?????010?????1111011")
  def VSSEGH             = Bits("b???000100000?????010?????1111011")
  def VSSEGB             = Bits("b???000000000?????010?????1111011")
  def VFSSEGD            = Bits("b???101100000?????010?????1111011")
  def VFSSEGW            = Bits("b???101000000?????010?????1111011")
  def VSSEGSTD           = Bits("b???0011??????????011?????1111011")
  def VSSEGSTW           = Bits("b???0010??????????011?????1111011")
  def VSSEGSTH           = Bits("b???0001??????????011?????1111011")
  def VSSEGSTB           = Bits("b???0000??????????011?????1111011")
  def VFSSEGSTD          = Bits("b???1011??????????011?????1111011")
  def VFSSEGSTW          = Bits("b???1010??????????011?????1111011")
  
  /* Automatically generated by parse-opcodes */
  def VLD                = Bits("b000001100000?????010?????1011011")
  def VLW                = Bits("b000001000000?????010?????1011011")
  def VLWU               = Bits("b000011000000?????010?????1011011")
  def VLH                = Bits("b000000100000?????010?????1011011")
  def VLHU               = Bits("b000010100000?????010?????1011011")
  def VLB                = Bits("b000000000000?????010?????1011011")
  def VLBU               = Bits("b000010000000?????010?????1011011")
  def VFLD               = Bits("b000101100000?????010?????1011011")
  def VFLW               = Bits("b000101000000?????010?????1011011")
  def VLSTD              = Bits("b0000011??????????011?????1011011")
  def VLSTW              = Bits("b0000010??????????011?????1011011")
  def VLSTWU             = Bits("b0000110??????????011?????1011011")
  def VLSTH              = Bits("b0000001??????????011?????1011011")
  def VLSTHU             = Bits("b0000101??????????011?????1011011")
  def VLSTB              = Bits("b0000000??????????011?????1011011")
  def VLSTBU             = Bits("b0000100??????????011?????1011011")
  def VFLSTD             = Bits("b0001011??????????011?????1011011")
  def VFLSTW             = Bits("b0001010??????????011?????1011011")
  def VSD                = Bits("b000001100000?????010?????1111011")
  def VSW                = Bits("b000001000000?????010?????1111011")
  def VSH                = Bits("b000000100000?????010?????1111011")
  def VSB                = Bits("b000000000000?????010?????1111011")
  def VFSD               = Bits("b000101100000?????010?????1111011")
  def VFSW               = Bits("b000101000000?????010?????1111011")
  def VSSTD              = Bits("b0000011??????????011?????1111011")
  def VSSTW              = Bits("b0000010??????????011?????1111011")
  def VSSTH              = Bits("b0000001??????????011?????1111011")
  def VSSTB              = Bits("b0000000??????????011?????1111011")
  def VFSSTD             = Bits("b0001011??????????011?????1111011")
  def VFSSTW             = Bits("b0001010??????????011?????1111011")
}

object Instructions
{
  /* Automatically generated by parse-opcodes */
  def STOP               = Bits("b00000000000000000101000001110111")
  def UTIDX              = Bits("b00000000000000000110?????1110111")
  def MOVZ               = Bits("b0000000??????????111?????1110111")
  def MOVN               = Bits("b0000001??????????111?????1110111")
  def FMOVZ              = Bits("b0000010??????????111?????1110111")
  def FMOVN              = Bits("b0000011??????????111?????1110111")

  def FADD_H             = Bits("b0000010??????????????????1010011")
  def FSUB_H             = Bits("b0000110??????????????????1010011")
  def FMUL_H             = Bits("b0001010??????????????????1010011")
  def FLH                = Bits("b?????????????????001?????0000111")
  def FSH                = Bits("b?????????????????001?????0100111")
}
