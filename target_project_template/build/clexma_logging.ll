; ModuleID = '/home/clexma/Desktop/fox3/llvm_passes/target_project_template/src/clexma_logging.c'
source_filename = "/home/clexma/Desktop/fox3/llvm_passes/target_project_template/src/clexma_logging.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [71 x i8] c"[OBJ ALLOC] malloc result: %p, in file: %s, at line: %d, variable: %s\0A\00", align 1, !dbg !0
@.str.1 = private unnamed_addr constant [78 x i8] c"[OBJ FREE] free result: %p freed, in file %s, at line %d, variable freed: %s\0A\00", align 1, !dbg !7
@.str.2 = private unnamed_addr constant [72 x i8] c"[AFTER FREE] freed ptr: %p, in file %s, at line %d, variable freed: %s\0A\00", align 1, !dbg !12
@.str.3 = private unnamed_addr constant [73 x i8] c"[STORE RESULT] store ptr: %p, in file %s, at line %d, variable name: %s\0A\00", align 1, !dbg !17
@.str.4 = private unnamed_addr constant [71 x i8] c"[STACK PTR VAR CREATED] ptr variable name: %s, in file %s, at line %d\0A\00", align 1, !dbg !22

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @clexma_log_malloc_result(ptr noundef %0, ptr noundef %1, i32 noundef %2, ptr noundef %3) #0 !dbg !35 {
  %5 = alloca ptr, align 8
  %6 = alloca ptr, align 8
  %7 = alloca i32, align 4
  %8 = alloca ptr, align 8
  store ptr %0, ptr %5, align 8
    #dbg_declare(ptr %5, !43, !DIExpression(), !44)
  store ptr %1, ptr %6, align 8
    #dbg_declare(ptr %6, !45, !DIExpression(), !46)
  store i32 %2, ptr %7, align 4
    #dbg_declare(ptr %7, !47, !DIExpression(), !48)
  store ptr %3, ptr %8, align 8
    #dbg_declare(ptr %8, !49, !DIExpression(), !50)
  %9 = load ptr, ptr %5, align 8, !dbg !51
  %10 = load ptr, ptr %6, align 8, !dbg !52
  %11 = load i32, ptr %7, align 4, !dbg !53
  %12 = load ptr, ptr %8, align 8, !dbg !54
  %13 = call i32 (ptr, ...) @printf(ptr noundef @.str, ptr noundef %9, ptr noundef %10, i32 noundef %11, ptr noundef %12), !dbg !55
  ret void, !dbg !56
}

declare i32 @printf(ptr noundef, ...) #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @clexma_log_before_free_result(ptr noundef %0, ptr noundef %1, i32 noundef %2, ptr noundef %3) #0 !dbg !57 {
  %5 = alloca ptr, align 8
  %6 = alloca ptr, align 8
  %7 = alloca i32, align 4
  %8 = alloca ptr, align 8
  store ptr %0, ptr %5, align 8
    #dbg_declare(ptr %5, !58, !DIExpression(), !59)
  store ptr %1, ptr %6, align 8
    #dbg_declare(ptr %6, !60, !DIExpression(), !61)
  store i32 %2, ptr %7, align 4
    #dbg_declare(ptr %7, !62, !DIExpression(), !63)
  store ptr %3, ptr %8, align 8
    #dbg_declare(ptr %8, !64, !DIExpression(), !65)
  %9 = load ptr, ptr %5, align 8, !dbg !66
  %10 = load ptr, ptr %6, align 8, !dbg !67
  %11 = load i32, ptr %7, align 4, !dbg !68
  %12 = load ptr, ptr %8, align 8, !dbg !69
  %13 = call i32 (ptr, ...) @printf(ptr noundef @.str.1, ptr noundef %9, ptr noundef %10, i32 noundef %11, ptr noundef %12), !dbg !70
  ret void, !dbg !71
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @clexma_log_after_free_result(ptr noundef %0, ptr noundef %1, i32 noundef %2, ptr noundef %3) #0 !dbg !72 {
  %5 = alloca ptr, align 8
  %6 = alloca ptr, align 8
  %7 = alloca i32, align 4
  %8 = alloca ptr, align 8
  store ptr %0, ptr %5, align 8
    #dbg_declare(ptr %5, !73, !DIExpression(), !74)
  store ptr %1, ptr %6, align 8
    #dbg_declare(ptr %6, !75, !DIExpression(), !76)
  store i32 %2, ptr %7, align 4
    #dbg_declare(ptr %7, !77, !DIExpression(), !78)
  store ptr %3, ptr %8, align 8
    #dbg_declare(ptr %8, !79, !DIExpression(), !80)
  %9 = load ptr, ptr %5, align 8, !dbg !81
  %10 = load ptr, ptr %6, align 8, !dbg !82
  %11 = load i32, ptr %7, align 4, !dbg !83
  %12 = load ptr, ptr %8, align 8, !dbg !84
  %13 = call i32 (ptr, ...) @printf(ptr noundef @.str.2, ptr noundef %9, ptr noundef %10, i32 noundef %11, ptr noundef %12), !dbg !85
  ret void, !dbg !86
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @clexma_log_store_result(ptr noundef %0, ptr noundef %1, i32 noundef %2, ptr noundef %3) #0 !dbg !87 {
  %5 = alloca ptr, align 8
  %6 = alloca ptr, align 8
  %7 = alloca i32, align 4
  %8 = alloca ptr, align 8
  store ptr %0, ptr %5, align 8
    #dbg_declare(ptr %5, !88, !DIExpression(), !89)
  store ptr %1, ptr %6, align 8
    #dbg_declare(ptr %6, !90, !DIExpression(), !91)
  store i32 %2, ptr %7, align 4
    #dbg_declare(ptr %7, !92, !DIExpression(), !93)
  store ptr %3, ptr %8, align 8
    #dbg_declare(ptr %8, !94, !DIExpression(), !95)
  %9 = load ptr, ptr %5, align 8, !dbg !96
  %10 = load ptr, ptr %6, align 8, !dbg !97
  %11 = load i32, ptr %7, align 4, !dbg !98
  %12 = load ptr, ptr %8, align 8, !dbg !99
  %13 = call i32 (ptr, ...) @printf(ptr noundef @.str.3, ptr noundef %9, ptr noundef %10, i32 noundef %11, ptr noundef %12), !dbg !100
  ret void, !dbg !101
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @clexma_log_alloca_result(ptr noundef %0, ptr noundef %1, i32 noundef %2) #0 !dbg !102 {
  %4 = alloca ptr, align 8
  %5 = alloca ptr, align 8
  %6 = alloca i32, align 4
  store ptr %0, ptr %4, align 8
    #dbg_declare(ptr %4, !105, !DIExpression(), !106)
  store ptr %1, ptr %5, align 8
    #dbg_declare(ptr %5, !107, !DIExpression(), !108)
  store i32 %2, ptr %6, align 4
    #dbg_declare(ptr %6, !109, !DIExpression(), !110)
  %7 = load ptr, ptr %4, align 8, !dbg !111
  %8 = load ptr, ptr %5, align 8, !dbg !112
  %9 = load i32, ptr %6, align 4, !dbg !113
  %10 = call i32 (ptr, ...) @printf(ptr noundef @.str.4, ptr noundef %7, ptr noundef %8, i32 noundef %9), !dbg !114
  ret void, !dbg !115
}

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.dbg.cu = !{!24}
!llvm.module.flags = !{!27, !28, !29, !30, !31, !32, !33}
!llvm.ident = !{!34}

!0 = !DIGlobalVariableExpression(var: !1, expr: !DIExpression())
!1 = distinct !DIGlobalVariable(scope: null, file: !2, line: 6, type: !3, isLocal: true, isDefinition: true)
!2 = !DIFile(filename: "src/clexma_logging.c", directory: "/home/clexma/Desktop/fox3/llvm_passes/target_project_template", checksumkind: CSK_MD5, checksum: "9664e6584067eca1591dc473c7d6c7bb")
!3 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 568, elements: !5)
!4 = !DIBasicType(name: "char", size: 8, encoding: DW_ATE_signed_char)
!5 = !{!6}
!6 = !DISubrange(count: 71)
!7 = !DIGlobalVariableExpression(var: !8, expr: !DIExpression())
!8 = distinct !DIGlobalVariable(scope: null, file: !2, line: 10, type: !9, isLocal: true, isDefinition: true)
!9 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 624, elements: !10)
!10 = !{!11}
!11 = !DISubrange(count: 78)
!12 = !DIGlobalVariableExpression(var: !13, expr: !DIExpression())
!13 = distinct !DIGlobalVariable(scope: null, file: !2, line: 14, type: !14, isLocal: true, isDefinition: true)
!14 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 576, elements: !15)
!15 = !{!16}
!16 = !DISubrange(count: 72)
!17 = !DIGlobalVariableExpression(var: !18, expr: !DIExpression())
!18 = distinct !DIGlobalVariable(scope: null, file: !2, line: 18, type: !19, isLocal: true, isDefinition: true)
!19 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 584, elements: !20)
!20 = !{!21}
!21 = !DISubrange(count: 73)
!22 = !DIGlobalVariableExpression(var: !23, expr: !DIExpression())
!23 = distinct !DIGlobalVariable(scope: null, file: !2, line: 22, type: !3, isLocal: true, isDefinition: true)
!24 = distinct !DICompileUnit(language: DW_LANG_C11, file: !25, producer: "clang version 21.0.0git", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, globals: !26, splitDebugInlining: false, nameTableKind: None)
!25 = !DIFile(filename: "/home/clexma/Desktop/fox3/llvm_passes/target_project_template/src/clexma_logging.c", directory: "/home/clexma/Desktop/fox3/llvm_passes/target_project_template", checksumkind: CSK_MD5, checksum: "9664e6584067eca1591dc473c7d6c7bb")
!26 = !{!0, !7, !12, !17, !22}
!27 = !{i32 7, !"Dwarf Version", i32 5}
!28 = !{i32 2, !"Debug Info Version", i32 3}
!29 = !{i32 1, !"wchar_size", i32 4}
!30 = !{i32 8, !"PIC Level", i32 2}
!31 = !{i32 7, !"PIE Level", i32 2}
!32 = !{i32 7, !"uwtable", i32 2}
!33 = !{i32 7, !"frame-pointer", i32 2}
!34 = !{!"clang version 21.0.0git"}
!35 = distinct !DISubprogram(name: "clexma_log_malloc_result", scope: !2, file: !2, line: 5, type: !36, scopeLine: 5, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !24, retainedNodes: !42)
!36 = !DISubroutineType(types: !37)
!37 = !{null, !38, !39, !41, !39}
!38 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: null, size: 64)
!39 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !40, size: 64)
!40 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !4)
!41 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!42 = !{}
!43 = !DILocalVariable(name: "ptr", arg: 1, scope: !35, file: !2, line: 5, type: !38)
!44 = !DILocation(line: 5, column: 37, scope: !35)
!45 = !DILocalVariable(name: "filename", arg: 2, scope: !35, file: !2, line: 5, type: !39)
!46 = !DILocation(line: 5, column: 54, scope: !35)
!47 = !DILocalVariable(name: "line", arg: 3, scope: !35, file: !2, line: 5, type: !41)
!48 = !DILocation(line: 5, column: 68, scope: !35)
!49 = !DILocalVariable(name: "varname", arg: 4, scope: !35, file: !2, line: 5, type: !39)
!50 = !DILocation(line: 5, column: 86, scope: !35)
!51 = !DILocation(line: 6, column: 87, scope: !35)
!52 = !DILocation(line: 6, column: 92, scope: !35)
!53 = !DILocation(line: 6, column: 102, scope: !35)
!54 = !DILocation(line: 6, column: 108, scope: !35)
!55 = !DILocation(line: 6, column: 5, scope: !35)
!56 = !DILocation(line: 7, column: 1, scope: !35)
!57 = distinct !DISubprogram(name: "clexma_log_before_free_result", scope: !2, file: !2, line: 9, type: !36, scopeLine: 9, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !24, retainedNodes: !42)
!58 = !DILocalVariable(name: "ptr", arg: 1, scope: !57, file: !2, line: 9, type: !38)
!59 = !DILocation(line: 9, column: 42, scope: !57)
!60 = !DILocalVariable(name: "filename", arg: 2, scope: !57, file: !2, line: 9, type: !39)
!61 = !DILocation(line: 9, column: 59, scope: !57)
!62 = !DILocalVariable(name: "line", arg: 3, scope: !57, file: !2, line: 9, type: !41)
!63 = !DILocation(line: 9, column: 73, scope: !57)
!64 = !DILocalVariable(name: "varname", arg: 4, scope: !57, file: !2, line: 9, type: !39)
!65 = !DILocation(line: 9, column: 91, scope: !57)
!66 = !DILocation(line: 10, column: 94, scope: !57)
!67 = !DILocation(line: 10, column: 99, scope: !57)
!68 = !DILocation(line: 10, column: 109, scope: !57)
!69 = !DILocation(line: 10, column: 115, scope: !57)
!70 = !DILocation(line: 10, column: 5, scope: !57)
!71 = !DILocation(line: 11, column: 1, scope: !57)
!72 = distinct !DISubprogram(name: "clexma_log_after_free_result", scope: !2, file: !2, line: 13, type: !36, scopeLine: 13, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !24, retainedNodes: !42)
!73 = !DILocalVariable(name: "ptr", arg: 1, scope: !72, file: !2, line: 13, type: !38)
!74 = !DILocation(line: 13, column: 41, scope: !72)
!75 = !DILocalVariable(name: "filename", arg: 2, scope: !72, file: !2, line: 13, type: !39)
!76 = !DILocation(line: 13, column: 58, scope: !72)
!77 = !DILocalVariable(name: "line", arg: 3, scope: !72, file: !2, line: 13, type: !41)
!78 = !DILocation(line: 13, column: 72, scope: !72)
!79 = !DILocalVariable(name: "varname", arg: 4, scope: !72, file: !2, line: 13, type: !39)
!80 = !DILocation(line: 13, column: 90, scope: !72)
!81 = !DILocation(line: 14, column: 88, scope: !72)
!82 = !DILocation(line: 14, column: 93, scope: !72)
!83 = !DILocation(line: 14, column: 103, scope: !72)
!84 = !DILocation(line: 14, column: 109, scope: !72)
!85 = !DILocation(line: 14, column: 5, scope: !72)
!86 = !DILocation(line: 15, column: 1, scope: !72)
!87 = distinct !DISubprogram(name: "clexma_log_store_result", scope: !2, file: !2, line: 17, type: !36, scopeLine: 17, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !24, retainedNodes: !42)
!88 = !DILocalVariable(name: "ptr", arg: 1, scope: !87, file: !2, line: 17, type: !38)
!89 = !DILocation(line: 17, column: 36, scope: !87)
!90 = !DILocalVariable(name: "filename", arg: 2, scope: !87, file: !2, line: 17, type: !39)
!91 = !DILocation(line: 17, column: 53, scope: !87)
!92 = !DILocalVariable(name: "line", arg: 3, scope: !87, file: !2, line: 17, type: !41)
!93 = !DILocation(line: 17, column: 67, scope: !87)
!94 = !DILocalVariable(name: "varname", arg: 4, scope: !87, file: !2, line: 17, type: !39)
!95 = !DILocation(line: 17, column: 85, scope: !87)
!96 = !DILocation(line: 18, column: 89, scope: !87)
!97 = !DILocation(line: 18, column: 94, scope: !87)
!98 = !DILocation(line: 18, column: 104, scope: !87)
!99 = !DILocation(line: 18, column: 110, scope: !87)
!100 = !DILocation(line: 18, column: 5, scope: !87)
!101 = !DILocation(line: 19, column: 1, scope: !87)
!102 = distinct !DISubprogram(name: "clexma_log_alloca_result", scope: !2, file: !2, line: 21, type: !103, scopeLine: 21, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !24, retainedNodes: !42)
!103 = !DISubroutineType(types: !104)
!104 = !{null, !39, !39, !41}
!105 = !DILocalVariable(name: "varname", arg: 1, scope: !102, file: !2, line: 21, type: !39)
!106 = !DILocation(line: 21, column: 43, scope: !102)
!107 = !DILocalVariable(name: "filename", arg: 2, scope: !102, file: !2, line: 21, type: !39)
!108 = !DILocation(line: 21, column: 64, scope: !102)
!109 = !DILocalVariable(name: "line", arg: 3, scope: !102, file: !2, line: 21, type: !41)
!110 = !DILocation(line: 21, column: 78, scope: !102)
!111 = !DILocation(line: 22, column: 87, scope: !102)
!112 = !DILocation(line: 22, column: 96, scope: !102)
!113 = !DILocation(line: 22, column: 106, scope: !102)
!114 = !DILocation(line: 22, column: 5, scope: !102)
!115 = !DILocation(line: 23, column: 1, scope: !102)
