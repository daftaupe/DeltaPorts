--- libr/io/p/io_self.c.orig	2019-05-15 07:39:46 UTC
+++ libr/io/p/io_self.c
@@ -750,11 +750,10 @@ exit:
 	kvm_read (k, (uintptr_t)p.p_vmspace, (ut8 *)&vs, sizeof (vs));
 
 	map = &vs.vm_map;
-	ep = map->header.next;
+	ep = kvm_vm_map_entry_first(k, map, &entry);
 
-	while (ep != &p.p_vmspace->vm_map.header) {
+	while (ep) {
 		int perm = 0;
-		kvm_read (k, (uintptr_t)ep, (ut8 *)&entry, sizeof (entry));
 		if (entry.protection & VM_PROT_READ) {
 			perm |= R_PERM_R;
 		}
@@ -767,16 +766,16 @@ exit:
 		}
 
 		io->cb_printf (" %p - %p %s [off. %zu]\n",
-				(void *)entry.start,
-				(void *)entry.end,
-				r_tr_rwx_i (perm),
-				entry.offset);
+				(void *)entry.ba.start,
+				(void *)entry.ba.end,
+				r_str_rwx_i (perm),
+				entry.ba.offset);
 
-		self_sections[self_sections_count].from = entry.start;
-		self_sections[self_sections_count].to = entry.end;
+		self_sections[self_sections_count].from = entry.ba.start;
+		self_sections[self_sections_count].to = entry.ba.end;
 		self_sections[self_sections_count].perm = perm;
 		self_sections_count++;
-		ep = entry.next;
+		ep = kvm_vm_map_entry_next(k, ep, &entry);
 	}
 
 	kvm_close (k);
