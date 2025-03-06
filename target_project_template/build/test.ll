; ModuleID = '/home/clexma/Desktop/fox3/llvm_passes/target_project_template/src/test.c'
source_filename = "/home/clexma/Desktop/fox3/llvm_passes/target_project_template/src/test.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct.T = type { ptr }

@.str = private unnamed_addr constant [71 x i8] c"[OBJ ALLOC] malloc result: %p, in file: %s, at line: %d, variable: %s\0A\00", align 1, !dbg !0
@.str.1 = private unnamed_addr constant [78 x i8] c"[OBJ FREE] free result: %p freed, in file %s, at line %d, variable freed: %s\0A\00", align 1, !dbg !7
@.str.2 = private unnamed_addr constant [72 x i8] c"[AFTER FREE] freed ptr: %p, in file %s, at line %d, variable freed: %s\0A\00", align 1, !dbg !12

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 !dbg !28 {
  %1 = alloca i32, align 4
  %2 = alloca ptr, align 8
  %3 = alloca ptr, align 8
  store i32 0, ptr %1, align 4
  %4 = call noalias ptr @malloc(i64 noundef 4) #4, !dbg !33
  call void @free(ptr noundef %4) #5, !dbg !34
    #dbg_declare(ptr %2, !35, !DIExpression(), !40)
    #dbg_declare(ptr %3, !41, !DIExpression(), !42)
  %5 = call noalias ptr @malloc(i64 noundef 8) #4, !dbg !43
  store ptr %5, ptr %3, align 8, !dbg !44
  %6 = load ptr, ptr %3, align 8, !dbg !45
  call void @free(ptr noundef %6) #5, !dbg !46
  %7 = call noalias ptr @malloc(i64 noundef 8) #4, !dbg !47
  store ptr %7, ptr %2, align 8, !dbg !48
  %8 = load ptr, ptr %2, align 8, !dbg !49
  %9 = load ptr, ptr %3, align 8, !dbg !51
  %10 = getelementptr inbounds %struct.T, ptr %9, i64 1, !dbg !52
  %11 = icmp eq ptr %8, %10, !dbg !53
  br i1 %11, label %12, label %14, !dbg !53

12:                                               ; preds = %0
  %13 = load ptr, ptr %2, align 8, !dbg !54
  call void @free(ptr noundef %13) #5, !dbg !56
  br label %14, !dbg !57

14:                                               ; preds = %12, %0
  ret i32 0, !dbg !58
}

; Function Attrs: nounwind
declare void @free(ptr noundef) #1

; Function Attrs: nounwind allocsize(0)
declare noalias ptr @malloc(i64 noundef) #2

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @clexma_log_malloc_result(ptr noundef %0, ptr noundef %1, i32 noundef %2, ptr noundef %3) #0 !dbg !59 {
  %5 = alloca ptr, align 8
  %6 = alloca ptr, align 8
  %7 = alloca i32, align 4
  %8 = alloca ptr, align 8
  store ptr %0, ptr %5, align 8
    #dbg_declare(ptr %5, !65, !DIExpression(), !66)
  store ptr %1, ptr %6, align 8
    #dbg_declare(ptr %6, !67, !DIExpression(), !68)
  store i32 %2, ptr %7, align 4
    #dbg_declare(ptr %7, !69, !DIExpression(), !70)
  store ptr %3, ptr %8, align 8
    #dbg_declare(ptr %8, !71, !DIExpression(), !72)
  %9 = load ptr, ptr %5, align 8, !dbg !73
  %10 = load ptr, ptr %6, align 8, !dbg !74
  %11 = load i32, ptr %7, align 4, !dbg !75
  %12 = load ptr, ptr %8, align 8, !dbg !76
  %13 = call i32 (ptr, ...) @printf(ptr noundef @.str, ptr noundef %9, ptr noundef %10, i32 noundef %11, ptr noundef %12), !dbg !77
  ret void, !dbg !78
}

declare i32 @printf(ptr noundef, ...) #3

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @clexma_log_before_free_result(ptr noundef %0, ptr noundef %1, i32 noundef %2, ptr noundef %3) #0 !dbg !79 {
  %5 = alloca ptr, align 8
  %6 = alloca ptr, align 8
  %7 = alloca i32, align 4
  %8 = alloca ptr, align 8
  store ptr %0, ptr %5, align 8
    #dbg_declare(ptr %5, !80, !DIExpression(), !81)
  store ptr %1, ptr %6, align 8
    #dbg_declare(ptr %6, !82, !DIExpression(), !83)
  store i32 %2, ptr %7, align 4
    #dbg_declare(ptr %7, !84, !DIExpression(), !85)
  store ptr %3, ptr %8, align 8
    #dbg_declare(ptr %8, !86, !DIExpression(), !87)
  %9 = load ptr, ptr %5, align 8, !dbg !88
  %10 = load ptr, ptr %6, align 8, !dbg !89
  %11 = load i32, ptr %7, align 4, !dbg !90
  %12 = load ptr, ptr %8, align 8, !dbg !91
  %13 = call i32 (ptr, ...) @printf(ptr noundef @.str.1, ptr noundef %9, ptr noundef %10, i32 noundef %11, ptr noundef %12), !dbg !92
  ret void, !dbg !93
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @clexma_log_after_free_result(ptr noundef %0, ptr noundef %1, i32 noundef %2, ptr noundef %3) #0 !dbg !94 {
  %5 = alloca ptr, align 8
  %6 = alloca ptr, align 8
  %7 = alloca i32, align 4
  %8 = alloca ptr, align 8
  store ptr %0, ptr %5, align 8
    #dbg_declare(ptr %5, !95, !DIExpression(), !96)
  store ptr %1, ptr %6, align 8
    #dbg_declare(ptr %6, !97, !DIExpression(), !98)
  store i32 %2, ptr %7, align 4
    #dbg_declare(ptr %7, !99, !DIExpression(), !100)
  store ptr %3, ptr %8, align 8
    #dbg_declare(ptr %8, !101, !DIExpression(), !102)
  %9 = load ptr, ptr %5, align 8, !dbg !103
  %10 = load ptr, ptr %6, align 8, !dbg !104
  %11 = load i32, ptr %7, align 4, !dbg !105
  %12 = load ptr, ptr %8, align 8, !dbg !106
  %13 = call i32 (ptr, ...) @printf(ptr noundef @.str.2, ptr noundef %9, ptr noundef %10, i32 noundef %11, ptr noundef %12), !dbg !107
  ret void, !dbg !108
}

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nounwind "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { nounwind allocsize(0) "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { nounwind allocsize(0) }
attributes #5 = { nounwind }

!llvm.dbg.cu = !{!17}
!llvm.module.flags = !{!20, !21, !22, !23, !24, !25, !26}
!llvm.ident = !{!27}

!0 = !DIGlobalVariableExpression(var: !1, expr: !DIExpression())
!1 = distinct !DIGlobalVariable(scope: null, file: !2, line: 24, type: !3, isLocal: true, isDefinition: true)
!2 = !DIFile(filename: "src/test.c", directory: "/home/clexma/Desktop/fox3/llvm_passes/target_project_template", checksumkind: CSK_MD5, checksum: "674eb5d63dc3b35b45bbc1f5dc7b5384")
!3 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 568, elements: !5)
!4 = !DIBasicType(name: "char", size: 8, encoding: DW_ATE_signed_char)
!5 = !{!6}
!6 = !DISubrange(count: 71)
!7 = !DIGlobalVariableExpression(var: !8, expr: !DIExpression())
!8 = distinct !DIGlobalVariable(scope: null, file: !2, line: 28, type: !9, isLocal: true, isDefinition: true)
!9 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 624, elements: !10)
!10 = !{!11}
!11 = !DISubrange(count: 78)
!12 = !DIGlobalVariableExpression(var: !13, expr: !DIExpression())
!13 = distinct !DIGlobalVariable(scope: null, file: !2, line: 32, type: !14, isLocal: true, isDefinition: true)
!14 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 576, elements: !15)
!15 = !{!16}
!16 = !DISubrange(count: 72)
!17 = distinct !DICompileUnit(language: DW_LANG_C11, file: !18, producer: "clang version 21.0.0git", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, globals: !19, splitDebugInlining: false, nameTableKind: None)
!18 = !DIFile(filename: "/home/clexma/Desktop/fox3/llvm_passes/target_project_template/src/test.c", directory: "/home/clexma/Desktop/fox3/llvm_passes/target_project_template", checksumkind: CSK_MD5, checksum: "674eb5d63dc3b35b45bbc1f5dc7b5384")
!19 = !{!0, !7, !12}
!20 = !{i32 7, !"Dwarf Version", i32 5}
!21 = !{i32 2, !"Debug Info Version", i32 3}
!22 = !{i32 1, !"wchar_size", i32 4}
!23 = !{i32 8, !"PIC Level", i32 2}
!24 = !{i32 7, !"PIE Level", i32 2}
!25 = !{i32 7, !"uwtable", i32 2}
!26 = !{i32 7, !"frame-pointer", i32 2}
!27 = !{!"clang version 21.0.0git"}
!28 = distinct !DISubprogram(name: "main", scope: !2, file: !2, line: 5, type: !29, scopeLine: 5, spFlags: DISPFlagDefinition, unit: !17, retainedNodes: !32)
!29 = !DISubroutineType(types: !30)
!30 = !{!31}
!31 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!32 = !{}
!33 = !DILocation(line: 6, column: 10, scope: !28)
!34 = !DILocation(line: 6, column: 5, scope: !28)
!35 = !DILocalVariable(name: "x", scope: !28, file: !2, line: 10, type: !36)
!36 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !37, size: 64)
!37 = distinct !DICompositeType(tag: DW_TAG_structure_type, name: "T", scope: !28, file: !2, line: 7, size: 64, elements: !38)
!38 = !{!39}
!39 = !DIDerivedType(tag: DW_TAG_member, name: "next", scope: !37, file: !2, line: 8, baseType: !36, size: 64)
!40 = !DILocation(line: 10, column: 15, scope: !28)
!41 = !DILocalVariable(name: "y", scope: !28, file: !2, line: 11, type: !36)
!42 = !DILocation(line: 11, column: 15, scope: !28)
!43 = !DILocation(line: 12, column: 9, scope: !28)
!44 = !DILocation(line: 12, column: 7, scope: !28)
!45 = !DILocation(line: 13, column: 10, scope: !28)
!46 = !DILocation(line: 13, column: 5, scope: !28)
!47 = !DILocation(line: 14, column: 9, scope: !28)
!48 = !DILocation(line: 14, column: 7, scope: !28)
!49 = !DILocation(line: 15, column: 9, scope: !50)
!50 = distinct !DILexicalBlock(scope: !28, file: !2, line: 15, column: 9)
!51 = !DILocation(line: 15, column: 14, scope: !50)
!52 = !DILocation(line: 15, column: 16, scope: !50)
!53 = !DILocation(line: 15, column: 11, scope: !50)
!54 = !DILocation(line: 17, column: 14, scope: !55)
!55 = distinct !DILexicalBlock(scope: !50, file: !2, line: 16, column: 5)
!56 = !DILocation(line: 17, column: 9, scope: !55)
!57 = !DILocation(line: 18, column: 5, scope: !55)
!58 = !DILocation(line: 19, column: 5, scope: !28)
!59 = distinct !DISubprogram(name: "clexma_log_malloc_result", scope: !2, file: !2, line: 23, type: !60, scopeLine: 23, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !17, retainedNodes: !32)
!60 = !DISubroutineType(types: !61)
!61 = !{null, !62, !63, !31, !63}
!62 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: null, size: 64)
!63 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !64, size: 64)
!64 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !4)
!65 = !DILocalVariable(name: "ptr", arg: 1, scope: !59, file: !2, line: 23, type: !62)
!66 = !DILocation(line: 23, column: 37, scope: !59)
!67 = !DILocalVariable(name: "filename", arg: 2, scope: !59, file: !2, line: 23, type: !63)
!68 = !DILocation(line: 23, column: 54, scope: !59)
!69 = !DILocalVariable(name: "line", arg: 3, scope: !59, file: !2, line: 23, type: !31)
!70 = !DILocation(line: 23, column: 68, scope: !59)
!71 = !DILocalVariable(name: "varname", arg: 4, scope: !59, file: !2, line: 23, type: !63)
!72 = !DILocation(line: 23, column: 86, scope: !59)
!73 = !DILocation(line: 24, column: 87, scope: !59)
!74 = !DILocation(line: 24, column: 92, scope: !59)
!75 = !DILocation(line: 24, column: 102, scope: !59)
!76 = !DILocation(line: 24, column: 108, scope: !59)
!77 = !DILocation(line: 24, column: 5, scope: !59)
!78 = !DILocation(line: 25, column: 1, scope: !59)
!79 = distinct !DISubprogram(name: "clexma_log_before_free_result", scope: !2, file: !2, line: 27, type: !60, scopeLine: 27, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !17, retainedNodes: !32)
!80 = !DILocalVariable(name: "ptr", arg: 1, scope: !79, file: !2, line: 27, type: !62)
!81 = !DILocation(line: 27, column: 42, scope: !79)
!82 = !DILocalVariable(name: "filename", arg: 2, scope: !79, file: !2, line: 27, type: !63)
!83 = !DILocation(line: 27, column: 59, scope: !79)
!84 = !DILocalVariable(name: "line", arg: 3, scope: !79, file: !2, line: 27, type: !31)
!85 = !DILocation(line: 27, column: 73, scope: !79)
!86 = !DILocalVariable(name: "varname", arg: 4, scope: !79, file: !2, line: 27, type: !63)
!87 = !DILocation(line: 27, column: 91, scope: !79)
!88 = !DILocation(line: 28, column: 94, scope: !79)
!89 = !DILocation(line: 28, column: 99, scope: !79)
!90 = !DILocation(line: 28, column: 109, scope: !79)
!91 = !DILocation(line: 28, column: 115, scope: !79)
!92 = !DILocation(line: 28, column: 5, scope: !79)
!93 = !DILocation(line: 29, column: 1, scope: !79)
!94 = distinct !DISubprogram(name: "clexma_log_after_free_result", scope: !2, file: !2, line: 31, type: !60, scopeLine: 31, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !17, retainedNodes: !32)
!95 = !DILocalVariable(name: "ptr", arg: 1, scope: !94, file: !2, line: 31, type: !62)
!96 = !DILocation(line: 31, column: 41, scope: !94)
!97 = !DILocalVariable(name: "filename", arg: 2, scope: !94, file: !2, line: 31, type: !63)
!98 = !DILocation(line: 31, column: 58, scope: !94)
!99 = !DILocalVariable(name: "line", arg: 3, scope: !94, file: !2, line: 31, type: !31)
!100 = !DILocation(line: 31, column: 72, scope: !94)
!101 = !DILocalVariable(name: "varname", arg: 4, scope: !94, file: !2, line: 31, type: !63)
!102 = !DILocation(line: 31, column: 90, scope: !94)
!103 = !DILocation(line: 32, column: 88, scope: !94)
!104 = !DILocation(line: 32, column: 93, scope: !94)
!105 = !DILocation(line: 32, column: 103, scope: !94)
!106 = !DILocation(line: 32, column: 109, scope: !94)
!107 = !DILocation(line: 32, column: 5, scope: !94)
!108 = !DILocation(line: 33, column: 1, scope: !94)
